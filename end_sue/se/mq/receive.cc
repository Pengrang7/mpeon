#include "header.h"

void receive() //메시지 큐 받음
{
    // mq.key = ftok("2", 64); // 키 번호
    // mq.msgid = msgget(mq.key, 0666 | IPC_CREAT); // 메시지 큐 id
        
    // msgrcv(mq.msgid, &msg, sizeof(msg)-sizeof(long), 0, 0); // 메시지 큐 받기

    // printf(" OP: %x  Temp Sensor: %x  StartTime: %d  EndTime: %d  Interval: %x Idata: %d \n", msg.opcode, msg.LN, msg.S, msg.E, msg.P, msg.Idata);
}

