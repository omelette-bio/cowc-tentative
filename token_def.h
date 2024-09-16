typedef enum _tokentype
{
  LEFT_MOVE, RIGHT_MOVE, INCR, DECR
} tokentype;

typedef struct _tokenliste 
{
  tokentype type;
  struct _tokenliste* suivant;
} tokenliste;
