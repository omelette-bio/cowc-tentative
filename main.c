#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "parser.h"
#include "analyser_semantique.h"

int main( int argc, char* argv[] )
{
  int file_input = open( argv[1], O_RDONLY );
  if ( file_input == -1 )
  {
    fprintf( stderr, "error opening the file: %s\n", argv[1] );
    return 1;
  }

  int sz;
  char* c = (char*)malloc(2048 * sizeof(char));

  sz = read(file_input, c, 2048);
  
  parse_chaine( c );
  print_liste();

  printf("\n");

  analyse_semantique();
//  tokentype tt1 = LEFT_MOVE;
//  ajout_token( tt1 );
//  tokentype tt2 = RIGHT_MOVE;
//  ajout_token( tt2 );
//  tokentype tt3 = INCR;
//  ajout_token( tt3 );
//  tokentype tt4 = DECR;
//  ajout_token( tt4 );

//  print_liste();
  
  return 0;
}
