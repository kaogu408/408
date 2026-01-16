#include <stdbool.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next; 
}LNode, *LinkList;

void InitLinkStack(LinkList *S){
    *S = (LNode *)malloc(sizeof(LNode));
    if(*S == NULL)
        return;
    (*S)->next = NULL;
}

bool LinkStackEmpty(LinkList S){
    return S->next == NULL;
}

bool PushLinkStack(LinkList *S, int e){
    LNode *P = (LNode *)malloc(sizeof(LNode));
    if(P == NULL)
        return false;

    P->data = e;
    P->next = (*S)->next;
    (*S)->next = P;
    return true;
}

bool PopLinkStack(LinkList *S, int *e){
    if(LinkStackEmpty(*S))
        return false;
    *e = (*S)->next->data;
    LNode *P = (*S)->next;
    (*S)->next = P->next;
    free(P);
    return true;
}

