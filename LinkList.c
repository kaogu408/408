#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next; 
}LNode, *LinkList;

LNode *GetElem(LinkList L, int i){
    if(i < 0)
        return NULL;
    LNode *p = L;
    int j = 0;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, int e){
    LNode *p = L;
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

bool InitList(LinkList L){
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL)
        return false;
    L->next = NULL;
    return true;
}

bool ListInsert(LinkList L, int i, int e){
    if(i < 1)
        return false;
/*    LNode *p = L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
*/
    LNode *p = GetElem(L, i-1);
    if(p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList L, int i, int *e){
    if(i < 1)
        return false;
/*    LNode *p = L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
*/
    LNode *p = GetElem(L, i-1);
    if(p == NULL || p->next == NULL)
        return false;
    LNode *q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return true;
}

bool Linkist_HeadInsert(LinkList *L){
    int e;
    *L = (LinkList)malloc(sizeof(LNode));
    if(L == NULL)
        return false;
    (*L)->next = NULL;
    scanf("%d", &e);
    while(e != 9999){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if(s == NULL)
            return false;
        s->data = e;
        s->next = (*L)->next;
        (*L)->next = s;
        scanf("%d", &e);
    }
    return true;
}

bool LinkList_TailInsert(LinkList *L){
    int e;
    *L = (LinkList)malloc(sizeof(LNode));
    if(*L == NULL)
        return false;
    LNode *r = *L;
    scanf("%d", &e);
    while(e != 9999){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if(s == NULL)
            return false;
        s->data = e;
        r->next = s;
        r = s;
        scanf("%d", &e);
    }
    r->next = NULL;
    return true;
}