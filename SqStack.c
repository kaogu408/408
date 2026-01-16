#include <stdbool.h>

#define MAXSIZE 10

typedef struct{
    int data[MAXSIZE];
    int top;
}SqStack;

typedef struct{
    int data[MAXSIZE];
    int top0;
    int top1;
}SqShareStack;

void InitStack(SqStack *S){
    S->top = -1;
}

bool StackEmpty(SqStack S){
    return S.top == -1;
}

bool PushStack(SqStack *S, int e){
    if(S->top == MAXSIZE-1)
        return false;
    S->data[++S->top] = e;
    return true;
}

bool PopStack(SqStack *S, int *e){
    if(StackEmpty(*S))
        return false;
    *e = S->data[S->top--];
    return true;
}

bool GetTopStack(SqStack S, int *e){
    if(StackEmpty(S))
        return false;
    *e = S.data[S.top];
    return true;
}

void InitShareStack(SqShareStack *S){
    S->top0 = -1;
    S->top1 = MAXSIZE;
}

bool ShareStackEmpty(SqShareStack S){
    return S.top0 == -1 && S.top1 == MAXSIZE;
}

bool PushShareStack(SqShareStack *S, int e){
    if(S->top0 == S->top1-1)
        return false;
    S->data[++S->top0] = e;
    return true;
}

int main(){
    SqStack S;
    InitStack(&S);
}