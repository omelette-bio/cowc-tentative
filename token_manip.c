#include <stdlib.h>
#include <stdio.h>
#include "token_def.h"

tokenliste* tl = NULL;


void ajout_token( tokentype tt )
{
  tokenliste* tl_t = tl;
  tokenliste* p = NULL;

  while ( tl_t != NULL )
  {
    p = tl_t;
    tl_t = tl_t->suivant;
  }
  
  if ( p == NULL )
  {
    tl = ( tokenliste* ) malloc(sizeof(tokenliste));
    
    if ( tl == NULL )
    {
      fprintf(stderr, "erreur de malloc\n");
      exit(1);
    }    
    
    tl->type = tt;
    tl->suivant = NULL;
  }
  else 
  {
    p->suivant = ( tokenliste* ) malloc(sizeof(tokenliste));
    
    if ( p == NULL )
    {
      fprintf(stderr, "erreur de malloc\n");
      exit(1);
    }
    
    p->suivant->type = tt;
    p->suivant->suivant = NULL;
  }
}


void print_type( tokentype tt )
{
  if ( tt == LEFT_MOVE ) printf("left ");
  if ( tt == RIGHT_MOVE ) printf("right ");
  if ( tt == INCR ) printf("++ ");
  if ( tt == DECR ) printf("-- ");
}

void print_liste()
{
  tokenliste* tl_t = tl;
  while( tl_t != NULL )
  {
    print_type( tl_t->type );
    tl_t = tl_t->suivant;
  }
}
