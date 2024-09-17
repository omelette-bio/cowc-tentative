#include <stdio.h>
#include <stdlib.h>
#include "token_manip.h"

void analyse_semantique()
{
  int valid_loop = 0;

  tokenliste* tl_t = get_liste();

  while ( tl_t != NULL )
  {
    if ( tl_t->type == LOOP_START ) valid_loop++;
    if ( tl_t->type == LOOP_END ) valid_loop--;

    tl_t = tl_t->suivant;
  }

  if ( valid_loop > 0 )
  {
    fprintf( stderr, "Too many loops started and not ended (%d).\n", valid_loop );
    exit(1);
  }
  if ( valid_loop < 0 )
  {
    fprintf( stderr, "Too many loops ended and not started (%d).\n", valid_loop );
    exit(1);
  }
}
