#include "stdafx.h"

int main()
{
	Stack S;
	int i;
	S = CreateStack();
	if(S != NULL)
		printf("Create Success\n");
	printf("»Î’ª\n");
	for(i = 0; i < 10; i++)
		Push(2*i+1, S);
	printf("\n≥ˆ’ª\n");
	while(!IsEmpty(S))
	{
		printf("%4d", Top(S));
		Pop(S);
	}
	printf("\n");
	return 0;
}