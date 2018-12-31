#include <iostream>
#include "sqstack.cpp"

int main()
{
	SqStack* s;
	initSqStack(s);
	std::cout << StackEmpty(s) << std::endl;
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	Push(s, 'e');
	while(s->top != -1)
	{
		ElemType e;
		if(!Pop(s, e))
		{
			break;
		}	
		std::cout << e << std::endl;
	}	

	std::cout << StackEmpty(s);
}
