#pragma once
#include<iostream>
#define MaxSize 50


using namespace std;

typedef int ElementType;

typedef struct
{
	ElementType data[MaxSize];
	int length;
} SqList;


class SequentialList
{
public:
	SequentialList();
	~SequentialList();
	void CreateList(SqList * &L, ElementType a[], int n);
	void InitList(SqList * &L);
	void DestroyList(SqList * &L);
	bool isListEmpty(SqList *L);
	int ListLength(SqList *L);
	void DispList(SqList * L);
	bool GetElem(SqList * L, int i, ElementType &e); 
	int LocateElem(SqList * L, ElementType e);
	bool ListInsert(SqList * &L, int i, ElementType e);
	bool ListDelete(SqList * &L, int i, ElementType &e);
};

