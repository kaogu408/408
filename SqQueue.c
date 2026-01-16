#include<stdbool.h>

#define MAXSIZE 10
typedef struct{
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

void InitQueue(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
}

bool QueueEmpty(SqQueue Q){
    return Q.front == Q.rear;
}

bool EnQueue(SqQueue *Q, int e){
    if((Q->rear+1)%MAXSIZE == Q->front)
        return false;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(SqQueue *Q, int *e){
    if(QueueEmpty(*Q))
        return false;
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return true;
}

bool GetHead(SqQueue Q, int *e){
    if(QueueEmpty(Q))
        return false;  
    *e = Q.data[Q.front];
    return true;
}