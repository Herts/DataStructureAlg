#include "SequentialList.h"

void SequentialList::CreateList(SqList * &L, ElementType a[], int n) {
	int i = 0, k = 0;
	L = (SqList *)malloc(sizeof(SqList));

	while (i < n) {
		L->data[k] = a[i];
		k++, i++;
	}

	L->length = k;
}

void SequentialList::InitList(SqList* &L) {
	L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;

}

void SequentialList::DestroyList(SqList* &L) {
	free(L);
}

bool SequentialList::isListEmpty(SqList * L) {
	return(L->length == 0);

}

int SequentialList::ListLength(SqList * L) {
	return L->length;
}

void SequentialList::DispList(SqList * L) {
	for (int i = 0; i < L->length; i++) {
		cout << L->data[i] << endl;
	}
	cout << endl;
}

bool SequentialList::GetElem(SqList *L, int i, ElementType &e) {
	if (i < 1 || i > L->length) {
		return false;
	}
	e = L->data[i];
	return true;

}

int SequentialList::LocateElem(SqList * L, ElementType e) {
	int i = 0;
	while (i < L->length && L->data[i] != e) {
		i++;
	}
	if (i >= L->length) {
		return 0;
	}
	else
	{
		return i + 1;

	}
}

bool SequentialList::ListInsert(SqList * &L, int i, ElementType e) {
	if (i < 1 || i >L->length + 1) {
		return false;
	}

	i--;

	for (int j = L->length; j > i; j--) {
		L->data[i] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return true;
}

bool SequentialList::ListDelete(SqList* &L, int i, ElementType &e) {
	if (i < 1 || i > L->length + 1) {
		return false;

	}
	i--;
	e = L->data[i];

	for (int j = L->length - 1; j > i; j--) {
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;

}


SequentialList::SequentialList()
{
}


SequentialList::~SequentialList()
{
}
