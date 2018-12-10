/***********************************************
 * 算法原理：
 * 1、一群人围成一圈 n
 * 2、从某个编号开始报数 k
 * 3、数到某个数m的人出列，从下一个重新开始报数
 * 4、一直循环，直达所有人出列
 * ********************************************/
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node * DCNode;
typedef DCNode DCListNode;
typedef DCNode DCLinkedList;
typedef int ElementType;

struct Node{
    ElementType elem;
    DCNode prior;
    DCNode next;
};

void InitList(DCLinkedList*);
void CreateRing(DCLinkedList,int);
int  Insert(DCLinkedList,int,ElementType);
void Josephus(DCLinkedList,int,int,int);
void Traverse(DCLinkedList);

int main(){
    int n, k, m;
    DCLinkedList list;
    printf("输入围成一环的人数n ( > 0) = ");
    scanf("%d",&n);
    printf("输入开始报数的编号k ( > 0) = ");
    scanf("%d",&k);
    printf("输入数到某个数出列m ( > 0) = ");
    scanf("%d",&m);
    InitList(&list);
    CreateRing(list,n);
    Traverse(list);
    Josephus(list,n,k,m);
    return 0;
}

void InitList(DCLinkedList* head){
    *head = (DCLinkedList)malloc(sizeof(DCNode));
    if(head == NULL){
        exit(-1);
    }
    (*head)->prior = *head;
    (*head)->next = *head;
}

void CreateRing(DCLinkedList head, int n){
    int i;
    for(i=1;i<=n;i++){
        if((Insert(head, i, i)) == -1){
            printf("位置不合法");
        }
    }
}

int Insert(DCLinkedList head, int index, ElementType elem){
    DCNode p,new;
    int i=1;
    p=head->next;
    while(p!=head&&i<index){
        p=p->next;
        i++;
    }
    if(i>index) return -1;
    if((new=(DCListNode)malloc(sizeof(DCNode))) == NULL){
        exit(-1);
    }
    new->elem = elem;
    new->prior=p->prior;
    new->next=p->prior->next;
    p->prior->next=new;
    p->prior=new;
    return 1;
}

void Traverse(DCLinkedList head){
    DCNode p;
    if(head==NULL)return;
    p=head->next;
    while(p!=head){
        printf("%4d",p->elem);
        p=p->next;
    }
    printf("\n");
}
DCNode GetNode(DCLinkedList head, int k){
    DCNode p;
    int i=1;
    p=head->next;
    while(p!=head&&i<k){
        p=p->next;
        i++;
    }
    if(p==head&&i>k) return NULL;
    return p;
}
void Delete(DCLinkedList head,int k){
    DCNode p;
    int i=1;
    p=head->next;
    while(p!=head&&i<k){
        p=p->next;
        i++;
    }
    if(p==head&&i>k)return;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
}
void RemoveHead(DCListNode head)
{
    head->prior->next=head->next;
    head->next->prior=head->prior;
    free(head);
}
void Josephus(DCLinkedList head, int n, int k, int m){
    DCNode p, startNode;
    startNode = GetNode(head,k);
    RemoveHead(head); // 去掉头结点开始循环,也可以在创建表的时候就不创建头结点
    while(n > 0){
        int i=1;
        while(i<m){
            startNode=startNode->next;
            i++;
        }
        p=startNode->next;
        startNode->prior->next=p;
        startNode->next->prior=startNode->prior;
        printf("编号为%d的人出列\n", startNode->elem);
        free(startNode);
        startNode=p;
        n--;
    }
    free(head);
    head=NULL;// 循环结束 删除表
}
