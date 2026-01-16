#include <stdbool.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

typedef struct Queue{
    LinkList front;
    LinkList rear;
}Queue;

bool InitStackQueue(Queue *Q){
    Q->front = Q->rear = (LNode *)malloc(sizeof(LNode));
    if(Q->front == NULL || Q->rear == NULL)
        return false;
    Q->front->next = NULL;
    return true;
}

bool QueueEmpty(Queue Q){
    return Q.front == Q.rear;        
}

bool EnQueue(Queue *Q, int e){
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = Q->rear->next;
    Q->rear->next = s;
    Q->rear = s;
    return true;
}

bool DeQueue(Queue *Q, int *e){
    if(QueueEmpty(*Q))
        return false;
    LNode *p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return true;
}