typedef enum _tokentype
{
  LEFT_MOVE, RIGHT_MOVE, 
  INCR, DECR,
  LOOP_START, LOOP_END,
  READ_INT, READ_ASCII,
  EXEC, RESET, REG_MANIP, PRINT
} tokentype;

typedef struct _tokenliste 
{
  tokentype type;
  struct _tokenliste* suivant;
} tokenliste;
