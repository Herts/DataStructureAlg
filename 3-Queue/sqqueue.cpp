#inclde <iostream>
#define MAX_SIZE 50

typedef char ElemType; 

struct SqQueue 
{
	ElemType data[MAX_SIZE];
	int front, rear;
};

void InitQueue(SqQueue *&q)
{
	q = new SqQueue;
	q->front = q->rear = -1;
}

void DestroyQueue(SqQueue *&q)
{
	delete q;
}

bool QueueEmpty(SqQueue * q)
{
	return (q->front == q->rear);
}

bool EnQueue(SqQueue *&q, ElemType e)
{
	if(q->rear == MAX_SIZE - 1)
		return false;

	q->rear++;
	q->data[q->rear] = e;
	return true;
}

bool DeQueue(SqQueue *&q, ElemType &e)
{
	if(q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}
