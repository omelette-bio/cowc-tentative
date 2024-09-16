#include <stdio.h>

inline void check_malloc( void* p )
{
  if ( p == NULL )
  {
    fprintf(stderr, "erreur de malloc\n");
    exit(1);
  }
}
