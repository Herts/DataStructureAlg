#include<iostream>

#define MAX_SIZE 50

typedef char ElemType;


typedef struct
{
	ElemType data[MAX_SIZE];
	int top;
} SqStack;

void initSqStack(SqStack *&s)
{
	s = new SqStack;
	s->top = -1;
}

void DestroyStack(SqStack * &s)
{
	delete s;
}

bool StackEmpty(SqStack *s) {
	return (s->top == -1);
}

bool Push(SqStack *&s, ElemType e) {
	if(s->top == MAX_SIZE -1) {
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack *&s, ElemType &e) {
	if(s->top == -1) {
	return false;
						}

	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack *&s, ElemType &e) {
	if(s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	return true;
}



