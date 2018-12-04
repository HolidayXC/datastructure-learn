#include<stdio.h>
#include"list.h"
int main()
{
    List L;
    int i;
    ElementType e;
    InitList(&L);
    for(i=1;i<=10;i++)
        InsertList(i*2-1, i, L);
    Traverse(L);
    if(Delete(7, L, &e) == SUCCESS)
        printf("删除第7个位置的元素：%d\n", e);
    else
        printf("位置不存在\n");
    Traverse(L);
    return 0;
}
