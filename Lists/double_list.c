#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode DList;
typedef int ElementType;

Position GetCurrentNode(DList head, int index);
struct Node
{
    ElementType e;
    Position prior;
    Position next;
};

void InitList(DList *head)
{
    *head = (DList)malloc(sizeof(Position));
    if(head == NULL)
        return;
    (*head)->prior = *head;
    (*head)->next = *head;
}
int IsEmpty(DList head)
{
    return head->next == NULL;
}
int Insert(DList head, int index, ElementType e)
{
    Position currentNode, newNode;
    currentNode = GetCurrentNode(head, index);
    if(NULL == currentNode)
        return -1;
    if((newNode = (Position)malloc(sizeof(Position))) == NULL)
        exit(-1);
    newNode->e=e;
    newNode->next=currentNode;
    newNode->prior=currentNode->prior;
    currentNode->prior->next=newNode;
    currentNode->prior=newNode;
    return 1;
}
int Delete(DList head, int index, ElementType *e)
{
    Position p;
    p=GetCurrentNode(head,index);
    if(NULL==p||p==head)
        return -1;

    p->prior->next=p->next;
    p->next->prior=p->prior;
    *e=p->e;
    free(p);
    return 1;
}
Position GetCurrentNode(DList head, int index)
{
    Position p;
    int i = 1;
    p = head->next;
    while(p!=head&&i<index)
    {
        p = p->next;
        i++;
    }
    if(i>index)
        return NULL;
    return p;
}
void Traverse(DList head)
{
    Position p;
    p=head->next;
    while(p!=head)
    {
        printf("%4d", p->e);
        p=p->next;
    }
    printf("\n");
}
void DestroyList(DList head)
{
    Position p, temp;
    p = head->next;
    while(p != head)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
}
int main()
{
    DList dlist;
    ElementType e;
    int i;
    InitList(&dlist);
    for(i=1;i<=5;i++)
        Insert(dlist, i, i*2-1);
    Traverse(dlist);
    Insert(dlist, 4, 2);
    Traverse(dlist);
    if(Delete(dlist, 4, &e)==1){
        printf("第4个位置的元素被删除:%d\n",e);
        Traverse(dlist);
    }else{
        printf("位置不合法\n");
    }
    DestroyList(dlist);
    return 0;
}
