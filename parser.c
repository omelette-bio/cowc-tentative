#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "token_manip.h"

void parse_chaine( char* entree )
{
  char* token = strtok( entree, " \n");

  while ( token != NULL )
  {
    if ( strcmp( token, "mOo") == 0 ) ajout_token( LEFT_MOVE );
    else if ( strcmp( token, "moO") == 0 ) ajout_token( RIGHT_MOVE );
    else if ( strcmp( token, "MOo") == 0 ) ajout_token( DECR );
    else if ( strcmp( token, "MoO") == 0 ) ajout_token( INCR );
    else if ( strcmp( token, "mOO") == 0 ) ajout_token( EXEC );
    else if ( strcmp( token, "MOO") == 0 ) ajout_token( LOOP_START );
    else if ( strcmp( token, "moo") == 0 ) ajout_token( LOOP_END );
    else if ( strcmp( token, "OOO") == 0 ) ajout_token( RESET );
    else if ( strcmp( token, "MMM") == 0 ) ajout_token( REG_MANIP );
    else if ( strcmp( token, "OOM") == 0 ) ajout_token( PRINT );
    else if ( strcmp( token, "oom") == 0 ) ajout_token( READ_INT );
    else if ( strcmp( token, "Moo") == 0 ) ajout_token( READ_ASCII );
    else 
    {
      fprintf(stderr, "Token non reconnu: %s.\n", token);
      exit(1);
    }
    token = strtok( NULL, " \n" );
  }
}
