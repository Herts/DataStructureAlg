#include<iostream>
#include"cirsqqueue.cpp"

int main(int argc, char** argv)
{
	SqQueue *q;
	InitQueue(q);
	std::cout << !QueueEmpty(q) << std::endl;
	EnQueue(q, 'a');
	EnQueue(q, 'b');
	EnQueue(q, 'c');

	Elemtype e;
	while(DeQueue(q, e)) {
		std::cout << e << std::endl;
	}

	std::cout << QueueEmpty(q) << std::endl;
	DestroyQueue(q);
}
