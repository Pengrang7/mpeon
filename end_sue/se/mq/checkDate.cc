#include "header.h"

bool checkDate(enum OP op, enum LN ln, enum P p)
{
	if ( op==OPCODE_LED)
	{
    if((ln >= LN_1 && ln <= LN_5) && (p >= P_1 && p <= P_3))
    {
      return true;
    }
    else
    {
      printf("error opcode: %d, led number: %d, parttern: %d\n", op, ln, p);
      return false;
    }
  }
  else if(op==OPCODE_TEMP)
  {
    if((ln>=1 && ln<=2))
    {
      printf(" TEMP Start \n");
      return true;
    }
    else
    {
      printf("error opcode: %d, ?: %d\n", op, ln);
      return false;
    }
  }
  else if(op==OPCODE_GPS)
  {
    if((ln>=1 && ln<=2))
    {
      printf(" GPS Start \n");
      return true;
    }
    else
    {
      printf("error opcode: %d, ?: %d\n", op, ln);
      return false;
    }
  }
	else 
  {
    printf("error opcode: %d \n", op);
		return false;
	}
}