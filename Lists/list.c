#include<malloc.h>
#include<stdlib.h>
#include"list.h"
struct Node
{
    ElementType e;
    Position next;
};

int IsEmpty(List L){ return L->next == NULL; }
int IsLast(Position P){ return P->next == NULL; }
Status Delete(Index I, List L, ElementType *e)
{
    Position preNode, nowNode;
    preNode = FindPrevious(I, L);
    if(preNode == NULL||preNode->next==NULL)
        return FAILED;
    nowNode = preNode->next;
    preNode->next = nowNode->next;
    *e = nowNode->e;
    free(nowNode);
    return SUCCESS;
}
Status Insert(ElementType X, Index I, List L)
{
    Position preNode, nowNode, newNode;
    preNode = FindPrevious(I, L);
    nowNode = preNode->next;
    newNode = (Position)malloc(sizeof(ListNode));
    if(newNode == NULL)
        exit(-1);
    preNode->next = newNode;
    newNode->next = nowNode;
    newNode->e = X;
    return SUCCESS;
}
Position FindPrevious(Index I, List L)
{
    int j = 0;
    Position P;
    P=L;
    while(P->next!=NULL&&j<I-1)
    {
        P=P->next;
        j++;
    }
    if(j!=I-1)
        return NULL;
    return P;
}
void DestroyList(List L)
{
    Position P, temp;
    P=L;
    while(P!=NULL)
    {
        temp = P->next;
        P->next=NULL;
        free(P);
        P=temp;
    }
}
void InitList(List *L)
{
    *L=(List)malloc(sizeof(ListNode));
    if(L==NULL)
        exit(-1);
    (*L)->next=NULL;
}
void Traverse(List L)
{
    Position P;
    printf("打印链表\n");
    P=L->next;
    while(P!=NULL)
    {
        printf("%4d", P->e);
        P=P->next;
    }
    printf("\n");
}
