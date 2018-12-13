#include <stdlib.h>
#include "myerror.h"

#include "stack.h"
struct Node
{
	ElementType Elem;
	PtrToNode Next;
};

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}
Stack CreateStack(void)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	if(S == NULL)
		FatalError("Out of space!");
	MakeEmpty(S);
	return S;
}
void DisposeStack(Stack S)
{
	PtrToNode TempCell;
	TempCell = S->Next;
	while(TempCell != NULL)
	{
		TempCell  = TempCell->Next;
		free(TempCell);
	}
	free(S);
}
void MakeEmpty(Stack S)
{
	if(S==NULL)
		Error("Must use CreateStack first");
	else
		while(!IsEmpty(S))
			Pop(S);
}
void Push(ElementType X, Stack S)
{
	PtrToNode TempCell;
	TempCell = (PtrToNode)malloc(sizeof(struct Node));
	if(TempCell)
		FatalError("Out of space");
	else
	{
		TempCell->Elem = X;
		TempCell->Next = S->Next;
		S->Next = TempCell;
	}
}
ElementType Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Elem;
	Error("Empty stack");
	return 0;
}
void Pop(Stack S)
{
	PtrToNode FirstCell;
	if(IsEmpty(S))
		Error("Empty stack");
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}