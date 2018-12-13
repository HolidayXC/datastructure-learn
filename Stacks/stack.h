#ifndef _STACK_H
typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack);
Stack CreateStack(void);
void DisposeStack(Stack);
void MakeEmpty(Stack);
void Push(ElementType, Stack);
ElementType Top(Stack);
void Pop(Stack);

#endif