#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int   counter = 0;

void sigint_handler( int signo)
{
   printf( "알람 발생 %d!!\n", counter++);
   alarm( 1);
}

int main( void)
{
   signal( SIGALRM, sigint_handler);
   alarm( 1 );
   while( counter<=3 )
      ;
}