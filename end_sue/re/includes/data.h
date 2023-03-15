#pragma once

#define IPC_DATA_MAX_SIZE 10

typedef struct {
  long			mtype;          //64bit = 8Byte
  uint32_t      opcode; //unsigned long 32비트 4바이트
  uint32_t      LN;
  uint32_t      P;
  uint32_t      S;
  uint32_t      E;
  // uint32_t      Idata;

  // uint32_t      data_size; //unsigned long 32비트 4바이트
  // uint8_t	    data[IPC_DATA_MAX_SIZE];  //unsigned char 8바이트 1비트
} stIpcMsg ;

typedef struct {
  long			mtype;          //64bit = 8Byte
  // uint32_t      opcode; //unsigned long 32비트 4바이트
  // uint32_t      LN;
  // uint32_t      P;
  // uint32_t      S;
  // uint32_t      E;
  uint32_t      Idata;

  // uint32_t      data_size; //unsigned long 32비트 4바이트
  // uint8_t	    data[IPC_DATA_MAX_SIZE];  //unsigned char 8바이트 1비트
} stIpcMsg2 ;

typedef enum OP{  OPCODE_LED = 1, OPCODE_TEMP, OPCODE_GPS } op;
typedef enum LN{ LN_1 =1, LN_2, LN_3, LN_4, LN_5 } ln;
typedef enum P{  P_1=1, P_2, P_3 } p;
typedef enum Time{  S, E } t;

typedef struct {
  char opcode1, LedNum1, patter1;
  int opcode, LedNum, patter, i;
  int z=1;
  int counter = 0;
} c_data;

typedef struct {
  key_t key;
  int msgid;
} stmq;

typedef struct {
  key_t key2;
  int msgid2;
} stmq2;

typedef struct {
  int StartTime, EndTime;

  time_t timer;
  struct tm* t;
} sttime;

extern c_data data;
extern stIpcMsg msg;
extern stIpcMsg2 msg2;
extern stmq mq;
extern stmq2 mq2;
extern sttime timer;