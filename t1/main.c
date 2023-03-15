//    https://leeyongjeon.tistory.com/entry/%ED%81%90Queues-%EB%B0%B0%EC%97%B4%EB%A1%9C-%EA%B5%AC%ED%98%84The-implementation-with-the-array

#include <stdio.h>

#define MAX     10

typedef struct queue{
    int head;
    int tail;
    int ar[MAX];
}QUEUE;

int queue_empty( QUEUE); //큐가 비어있는지 확인
void enqueue( QUEUE *, int); //큐에 데이터를 삽입
int dequeue( QUEUE *); //큐에서 데이터를 제거

#pragma region 

int main( void)
{
    QUEUE Q;

    // initialize the front and rear.
    Q.head  = 0;
    Q.tail  = 0;

    enqueue( &Q, 10); //삽입
    enqueue( &Q, 30); //삽입
    enqueue( &Q, 20); //삽입
    enqueue( &Q, 50); //삽입

    dequeue( &Q); //삭제
    dequeue( &Q); //삭제
    dequeue( &Q); //삭제
    dequeue( &Q); //삭제
    dequeue( &Q); //삭제
}

/*
    queue_empty( QUEUE)
    This function check whether the queue is empty.
*/
int queue_empty( QUEUE q) //큐가 비어있는지 확인
{
    if( q.head == q.tail)
        return 1;

    return 0;
}

/*
    enqueue( QUEUE *, int)
    insert a data into the queue
*/
void enqueue( QUEUE *q, int data) //큐에 데이터를 삽입
{
    q->ar[q->head++]    = data;

    printf("ENQUEUE : %d\n", data); 

    q->head = q->head % MAX;
}

/*
    dequeue( QUEUE *)
    remove a data from the queue and
    return the data.
*/
int dequeue( QUEUE *q) //큐에서 데이터를 제거
{
    int data;

    if( queue_empty( *q))
    {
        printf("the queue is empty!\n");

        return -1;
    }

    data    = q->ar[q->tail++];

    printf("DEQUEUE : %d\n", data);

    q->tail = q->tail % MAX;

    return data;
}
#pragma endregion


#pragma region 
//- 삽입 명령을 ENQUEUE라고 부른다.

//- 삭제 명령을 DEQUEUE라고 부른다.

// 1. 동작 원리

// (1) 삽입할 위치를 가리키는 head와 내보낼 위치를 가르키는 tail의 위치를 초기화 한다.

// (2) 삽입 명령 시 head가 가르키는 곳에 큐의 위치에 데이터를 입력하고 head의 값을 증가시킨다.

// (3 - 1) 삭제 명령 시 큐가 비어있는지 확인한다.

// (3 - 2) 큐에 데이터가 있다면, 해당 데이터를 반환하고 tail의 값을 증가시킨다.

// 2. 함수 설명

// int queue_empty( QUEUE) : 큐가 비어있는지 확인하는 기능을 수행한다.

// void enqueue( QUEUE *, int) : 큐에 데이터를 삽입하는 것으로 동작원리 (2)에 해당한다.

// int dequeue( QUEUE *) : 큐에서 데이터를 제거하는 것으로 동작원리 (3)에 해당한다.
#pragma endregion