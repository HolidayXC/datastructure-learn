
#include "stdafx.h"
struct Node
{
	ElementType Element;
	PtrToNode Next;
};
int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S;
	S = malloc(sizeof(struct Node));
	if(S == NULL)
	{
		printf("Out of space!!\n");
		return NULL;
	}
	S->Next= NULL;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S)
{
	if(S == NULL)
		printf("Must use CreateStack first\n");
	else
		while(!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X, Stack S)
{
	PtrToNode TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
	{
		printf("Out of space!!\n");
		return;
	}
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
	printf("%4d", X);
}

ElementType Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Element;
	printf("Empty Stack!!\n");
	return 0;
}

void Pop(Stack S)
{
	PtrToNode FirstCell;
	if(IsEmpty(S))
		printf("Empty Stack");
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}