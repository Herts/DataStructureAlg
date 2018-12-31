#include <iostream>

typedef char ElemType;

struct LinkNode
{
	ElemType data;
	LinkNode *next;
};

void InitStack(LinkNode *&s) {
	s = new LinkNode;
	s->next = NULL;
}

void DestroyStack(LinkNode *&s)
{
	LinkNode *pre = s, *p = s->next;
	while(p!=NULL)
	{
		delete pre;
		pre = p;
		p = pre->next;
	}
	delete pre;
}

bool StackEmpty(LinkNode *s)
{
	return (s->next==NULL);
}

void Push(LinkNode *&s, ElemType e)
{
	LinkNode *p;
	p = new LinkNode;
	p->data = e;
	p->next = s->next;
	s->next = p;
	
}

bool Pop(LinkNode *&s, ElemType &e)
{
	LinkNode *p;
	if(s->next==NULL)
	{
		return false;
	}
	p = s->next;
	e = p->data;
	s->next = p->next;
	delete p;
	return true;
}

bool GetTop(LinkNode * s, ElemType &e)
{
	if(s->next == NULL)
	{
		return false;
	}
	e = s->next->data;
	return true;
}


