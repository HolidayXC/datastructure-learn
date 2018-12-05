#ifndef __LIST__H
#define __LIST__H

#define SUCCESS 1
#define FAILED -1
struct Node;
typedef struct Node *ListNode; // 节点
typedef ListNode List; // 表
typedef ListNode Position; // 位置
typedef int Index;
typedef int Status;
typedef int ElementType; // 数据类型定义为整型
List MakeEmpty(List L); // 置空
int IsEmpty(List L);
int IsLast(Position P);
Position Find(Index I, List L);
Status Delete(Index I, List L, ElementType *e);
Status Insert(ElementType X, Index I, List L);
Position FindPrevious(Index I, List L);
void DestroyList(List L);
void InitList(List *L);
void Traverse(List L);
#endif /*__LIST__H*/
