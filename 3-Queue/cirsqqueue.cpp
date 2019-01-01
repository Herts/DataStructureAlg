#define MAX_SIZE 50

typedef char Elemtype;

struct SqQueue
{
	Elemtype data[MAX_SIZE];
	int front, rear;
};


void InitQueue(SqQueue *&q)
{
	q = new SqQueue;
	q->front = q->rear = 0;
}

void DestroyQueue(SqQueue *&q)
{
	delete q;
}

bool QueueEmpty(SqQueue *q)
{
	return (q->front == q->rear);
}

bool EnQueue(SqQueue *&q, Elemtype e)
{
	if( (q->rear+1) % MAX_SIZE == q->front)
		return false;

	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = e;
	return true;
}

bool DeQueue(SqQueue *&q, Elemtype &e)
{
	if(q->front == q->rear)
		return false;

	q->front = (q->front + 1 ) % MAX_SIZE;
	e = q->data[q->front];
	return true;
}

