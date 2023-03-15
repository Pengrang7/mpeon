#include "header.h"
#define SEND_MSGQ_KEY 0x99999902
bool checkDate(OP op, LN ln, P p);

void send() // 메시지 큐 보내기
{
  bool result = checkDate((OP)data.opcode, (LN)data.LedNum, (P)data.patter); // 데이터 검사
  
  if(result==true) // 데이터가 true면
  {
    msg.mtype = 1; // 메시지 타입(크기)
    msg.opcode=(uint32_t) data.opcode; // 형 변환
    msg.LN=(uint32_t) data.LedNum;
    msg.P=(uint32_t) data.patter;
    msg.S=(uint32_t) timer.StartTime;
    msg.E=(uint32_t) timer.EndTime;

    msgsnd(mq.msgid, &msg, sizeof(msg)-sizeof(long), IPC_NOWAIT); // 메시지 보내기
  }
  else 
  {
    printf(" error \n");
    exit(1);
  }
}