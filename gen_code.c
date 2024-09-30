#include <stdlib.h>
#include <stdio.h>
#include "token_manip.h"

void print_tab( int n )
{
  for ( int i = 0; i < n; i++ ) printf("\t");
}

void generer_code()
{
  printf("#include <stdio.h>\n");
  printf("#include <stdlib.h>\n");
  printf("\n");
  printf("int arr[3000];\n");
  printf("int i = 0;\n");
  printf("int* reg = NULL;");
  printf("\n");
  printf("int main()\n");
  printf("{\n");
  tokenliste* tl_t = get_liste();
  int indentation_level = 1;

  while ( tl_t != NULL )
  {
    print_tab(indentation_level);
    if ( tl_t->type == LEFT_MOVE ) printf("i-=%d;\n", tl_t->qty);
    else if ( tl_t->type == RIGHT_MOVE ) printf("i+=%d;\n", tl_t->qty);
    else if ( tl_t->type == INCR ) printf("arr[i]+=%d;\n", tl_t->qty);
    else if ( tl_t->type == DECR ) printf("arr[i]-=%d;\n", tl_t->qty);
    else if ( tl_t->type == LOOP_START ) 
    {
      printf("while ( arr[i] != 0 )\n");
      print_tab( indentation_level );
      printf("{\n");
      indentation_level++;  
    }
    else if ( tl_t->type == LOOP_END ) 
    {
      indentation_level--;
      printf("}\n");
    }
    else if ( tl_t->type == RESET ) printf("arr[i] = 0;\n");
    else if ( tl_t->type == PRINT ) printf("printf(\"%%d\\n\", arr[i]);\n");
    else if ( tl_t->type == REG_MANIP )
    {
      printf("if ( reg == NULL )\n");
      print_tab( indentation_level++ );
      printf("{\n");
      print_tab( indentation_level );
      printf("reg = malloc(sizeof(int));\n");
      print_tab( indentation_level );
      printf("if ( reg == NULL ) return 1;\n");
      print_tab( indentation_level );
      printf("*reg = arr[i];\n");
      print_tab( --indentation_level );
      printf("}\n");
      print_tab( indentation_level );
      printf("else\n");
      print_tab( indentation_level++ );
      printf("{\n");
      print_tab( indentation_level );
      printf("arr[i] = *reg;\n");
      print_tab( indentation_level );
      printf("reg = NULL;\n");
      print_tab( --indentation_level );
      printf("}\n");
    }

    tl_t = tl_t->suivant;
  }
  printf("}\n");
}
