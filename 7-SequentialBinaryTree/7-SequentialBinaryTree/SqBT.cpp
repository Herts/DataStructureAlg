#include<iostream>

typedef char ElemType;




int countLeaf(ElemType SqBinTree[], int Size) {
	int count = 0;

	for (int i = 1; i <= Size; i++) {
		if (SqBinTree[i] != '#' && (i > Size / 2 || SqBinTree[2 * i] == '#' && SqBinTree[2 * i + 1] == '#')) {
			count++;
		}
	}

	return count;

}


int main(int agrc, char** argv) {
	char SqBinTree[] = { 'A','B','C','D','E','#','F','#' };

	std::cout << countLeaf(SqBinTree, 8);

	system("pause");
}
