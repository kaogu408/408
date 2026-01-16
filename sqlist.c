#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef struct{
    int *data;
    int length;
}SqList;

bool InitList(SqList *L){
    L->data = (int *)malloc(MAXSIZE * sizeof(int));
    if(L->data == NULL)
        return false;
    L->length = 0;
    return true;
}

bool ListInsert(SqList *L, int i, int e){
    if(i < 1 || i > L->length+1 || L->length >= MAXSIZE)
        return false;
    for(int j = L->length; j >= i; j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool ListDelete(SqList *L, int i, int *e){
    if(i < 1 || i > L->length)
        return false;
    *e = L->data[i-1];
    for(int j = i; j < L->length; j++)
        L->data[j-1] = L->data[j];
    L->length--;
    return true;
}

int GetElem(SqList *L, int i){
    return L->data[i-1];
}

int LocateElem(SqList *L, int e){
    for(int i = 0; i < L->length; i++)
        if(L->data[i] == e)
            return i+1;
    return 0;
}

void ListShow(SqList *L){
    for(int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

int main(){
    SqList L;
    int e = -1;
    
    InitList(&L);
    ListShow(&L);
    ListInsert(&L, 1, 10);
    ListShow(&L);
    ListInsert(&L, 1, 11);
    ListShow(&L);
    ListInsert(&L, 3, 12);
    ListShow(&L);
    printf("Element at index 2: %d\n", GetElem(&L, 2));
    ListDelete(&L, 2, &e);
    ListShow(&L);
    printf("Deleted element: %d\n", e);
    printf("Element at index 2: %d\n", GetElem(&L, 2));
    printf("Index of element 12: %d\n", LocateElem(&L, 12));
    ListDelete(&L, LocateElem(&L, 12), &e);
    printf("Deleted element: %d\n", e);
    ListShow(&L);
    printf("Index of element 12: %d\n", LocateElem(&L, 12));
    return 0;
}