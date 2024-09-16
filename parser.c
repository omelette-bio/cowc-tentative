#include <string.h>
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

    token = strtok( NULL, " \n" );
  }
}
