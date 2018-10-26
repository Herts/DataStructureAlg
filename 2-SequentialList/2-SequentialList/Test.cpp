#include"SequentialList.h"

// T(n) = O(n), S(n) = O(n)
void delnode(SqList * &L, ElementType x) {
	int k = 0, i = 0;
	while (i < L->length) {
		if (L->data[i] == x) {
			k++;
		}
		else
		{
			L->data[i - k] = L->data[i];
		}
		i++;
	}
	L->length -= k;

}

int main(int argc, char ** args) {
	int a[] = { 1,34,56,4,3,1,6,7,6,4,6,2,943,44 };
	SequentialList * sq = new SequentialList();
	SqList * sqlist = new SqList();
	sq->CreateList(sqlist, a, 14);
	sq->DispList(sqlist);

	delnode(sqlist, 6);

	sq->DispList(sqlist);

}
