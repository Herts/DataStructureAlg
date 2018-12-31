#include<iostream>
#include "listack.cpp"

int main(){
	LinkNode *s;
	InitStack(s);
	std::cout << StackEmpty(s) << std::endl;
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	
	ElemType e;
	while(Pop(s, e))	
		std::cout << e << std::endl;

	std::cout << StackEmpty(s) << std::endl;

	DestroyStack(s);
}
