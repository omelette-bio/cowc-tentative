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
    tl->qty = 1;
    tl->suivant = NULL;
  }
  else 
  {
    if ( p->type == tt ) p->qty++;
    else 
    {
      p->suivant = ( tokenliste* ) malloc(sizeof(tokenliste));
    
      if ( p == NULL )
      {
        fprintf(stderr, "erreur de malloc\n");
        exit(1);
      }
    
      p->suivant->type = tt;
      p->suivant->qty = 1;
      p->suivant->suivant = NULL;
    }
  }
}


void print_type( tokentype tt )
{
  if ( tt == LEFT_MOVE ) printf("left ");
  if ( tt == RIGHT_MOVE ) printf("right ");
  if ( tt == INCR ) printf("++ ");
  if ( tt == DECR ) printf("-- ");
  if ( tt == LOOP_START ) printf("[ ");
  if ( tt == LOOP_END ) printf("] ");
  if ( tt == READ_INT ) printf("read_i ");
  if ( tt == READ_ASCII ) printf("read_a ");
  if ( tt == EXEC ) printf("exec ");
  if ( tt == RESET ) printf("reset ");
  if ( tt == REG_MANIP ) printf("reg ");
  if ( tt == PRINT ) printf("print ");
}

void print_liste()
{
  tokenliste* tl_t = tl;
  while( tl_t != NULL )
  {
    print_type( tl_t->type );
    printf("%d ", tl_t->qty);
    tl_t = tl_t->suivant;
  }
}

tokenliste* get_liste() 
{
  return tl;
}
