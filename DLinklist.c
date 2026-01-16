#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList *L){
    *L = (DNode *)malloc(sizeof(DNode));
    if(*L == NULL)
        return false;
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return true;
}

bool InsertNextDNode(DNode *p, DNode *s){
    if(p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if(p->next != NULL)
        p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true;
}

int main(){
    DLinkList L;
    InitDLinkList(&L);
    return 0;
}