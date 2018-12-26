#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
#include "queue.h"
#define MinQueueSize (5)
struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType * Array;
};
void Message(const char *s)
{
	printf("%s\n", s);
}
int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}
int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements)
{
	Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
	{
		printf("Out of space");
		return NULL;
	}
	if (MinQueueSize > MaxElements)
		MaxElements = MinQueueSize;
	Q->Capacity = MaxElements;
	Q->Array = (ElementType*)malloc(MaxElements * sizeof(ElementType));
	MakeEmpty(Q);
	return Q;
}
void Dispose(Queue Q)
{
	while (!IsEmpty(Q))
		Dequeue(Q);
}
void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}
static int Succ(int Value, Queue Q)
{
	if (++Value == Q->Capacity)
		Value = 0;
	return Value;
}
void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
	{
		Message("Full Queue");
		return;
	}
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}
ElementType Front(Queue Q)
{
	if (IsEmpty(Q))
		return -1;
	return Q->Array[Q->Front];
}
void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		Message("Empty Queue");
		return;
	}
	else
	{
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
	}
}
ElementType FrontAndDequeue(Queue Q)
{
	int Tmp;
	if (IsEmpty(Q))
	{
		Message("Empty Queue");
		return -1;
	}
	else
	{
		Q->Size--;
		Tmp = Q->Array[Q->Front];
		Q->Front = Succ(Q->Front, Q);
	}
	return Tmp;
}

int main()
{
	Message("Create Queue...");
	Queue Q = CreateQueue(3);
	int i = 1;
	Enqueue(1, Q);
	Enqueue(2, Q);
	Enqueue(3, Q);
	Enqueue(4, Q);
	Enqueue(5, Q);
	Dequeue(Q);
	Dequeue(Q);
	Enqueue(6, Q);
	Enqueue(7, Q);
	//Dispose(Q);
	while (!IsEmpty(Q))
	{
		printf("%d.st Dequeue is %d\n", i++, FrontAndDequeue(Q));
	}
	if(IsEmpty(Q))
		Message("Empty Queue...");
	return 0;
}
