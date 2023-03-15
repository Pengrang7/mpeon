#include "header.h"

bool checkDate(enum OP op, enum LN ln, enum P p) //데이터 유효성 검사 (?)
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
    printf(" TEMP Start \n");
    return true;
  }
  else if(op==OPCODE_GPS)
  {
    printf(" GPS Start \n");
    return true;
  }
	else 
  {
    printf("error opcode: %d \n", op);
		return false;
	}
}