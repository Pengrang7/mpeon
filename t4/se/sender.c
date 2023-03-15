#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define  BUFF_SIZE   1024

typedef struct {
   long  data_type;
   int   data_num;
   char  data_buff[BUFF_SIZE];
} t_data;

int main( void)
{
   int      msqid;
   int      ndx   = 0;
   t_data   data;

   if ( -1 == ( msqid = msgget( (key_t)1234, IPC_CREAT | 0666))){
      perror( "msgget() 실패");
      exit( 1);
   }

   while( 1 ){
      data.data_type = ( ndx++ % 3) +1;   // data_type 는 1, 2, 3
      data.data_num  = ndx;
      sprintf( data.data_buff, "type=%ld, ndx=%d, http://badayak.com", data.data_type, ndx);

      if ( -1 == msgsnd( msqid, &data, sizeof( t_data) - sizeof( long), 0)){
         perror( "msgsnd() 실패");
         exit( 1);
      }
      sleep( 1);
   }
}