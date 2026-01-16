#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 10
typedef struct{
    int num[MAXSIZE];
    int top;
}SqStack;

void initStack(SqStack *S){
    S->top = -1;
}

bool isFull(SqStack *S){
    return S->top == MAXSIZE - 1;
}

bool isEmpty(SqStack *S){
    return S->top == -1;
}

bool push(SqStack *S, int e){
    if(isFull(S))
        return false;
    S->num[++S->top] = e;
    return true;
}

bool pop(SqStack *S, int *e){
    if(isEmpty(S))
        return false;
    *e = S->num[S->top--];
    return true;
}

bool calc_num(int num_left, int num_right, char sym, int *res){
    switch (sym) {
        case '+': *res = num_left + num_right; break;
        case '-': *res = num_left - num_right; break;
        case '*': *res = num_left * num_right; break;
        case '/':
            if(num_right == 0){
                printf("错误：除数不能为0！\n");
                return false;
            }
            *res = num_left / num_right; 
            break;
        default:
            printf("错误：未知运算符 %c\n", sym);
            return false;
    }
    return true;
}

bool expressEval(int *eval, int len){
    SqStack S;
    int num_right, num_left, res;
    initStack(&S);

    for(int i = 0; i < len; i++){
        int val = eval[i];
        if(val != '+' && val != '-' && val != '*' && val != '/'){
            push(&S, val);
        }

        else{
            if(!pop(&S, &num_right) || !pop(&S, &num_left)){
                printf("错误：表达式非法，运算符过多，数字不足！\n");
                return false;
            }
            if(!calc_num(num_left, num_right, val, &res)){
                return false;
            }
            push(&S, res);
        }
    }

    if(S.top != 0){
        printf("错误：表达式非法，数字过多，运算符不足！\n");
        return false;
    }
    printf("后缀表达式计算结果 = %d\n", S.num[0]);
    return true;
}

int main(){

    int eval[] = {15,7,1,1,'+','-','/',3,'*',2,1,1,'+','+','-'};
    int len = sizeof(eval) / sizeof(eval[0]);

    expressEval(eval, len);
    return 0;
}