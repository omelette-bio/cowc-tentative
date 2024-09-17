#include <stdlib.h>
#include <stdio.h>
#include "token_manip.h"

void print_tab( int n )
{
  for ( int i = 0; i < n; i++ ) printf("\t");
}

void generer_code()
{
  printf("int arr[3000];\nint i = 0;\n\nint main()\n{\n");
  tokenliste* tl_t = get_liste();
  int indentation_level = 1;

  while ( tl_t != NULL )
  {
    print_tab(indentation_level);
    if ( tl_t->type == LEFT_MOVE ) printf("i--;\n");
    else if ( tl_t->type == RIGHT_MOVE ) printf("i++;\n");
    else if ( tl_t->type == INCR ) printf("arr[i]++;\n");
    else if ( tl_t->type == DECR ) printf("arr[i]--;\n");
    else if ( tl_t->type == LOOP_START ) 
    {
      printf("while ( arr[i] != 0 )\n{\n");
      indentation_level++;  
    }
    else if ( tl_t->type == LOOP_END ) 
    {
      indentation_level--;
      printf("}\n");
    }
    else if ( tl_t->type == RESET ) printf("arr[i] = 0;\n");
    else if ( tl_t->type == PRINT ) printf("printf(\"%%d\\n\", arr[i]);\n");

    tl_t = tl_t->suivant;
  }
  printf("}\n");
}
