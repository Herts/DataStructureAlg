#include <iostream>
#include "SqString.cpp"

void GetNextVal(SqString *t, int nextval[]) {
	int j = 0, k = -1, tLen = t->length;
	nextval[0] = -1;
	while( j < tLen)
	{
		if( k == -1 || t->data[j] == t->data[k] )
		{
			j++;
			k++;
			if(t->data[j] != t->data[k]) {
				nextval[j] = k;
				continue;
			}
			nextval[j] = nextval[k];
			continue;
		}
		k = nextval[k];
	}
}

int KMPIndex(SqString *s, SqString *t)
{
	int nextval[MAX_SIZE];
	int i = 0, j =0;
	int sLen = s->length, tLen = t->length;

	GetNextVal(s, nextval);
	while( i < sLen && j < tLen)
	{
		if(j == -1 || s->data[i] == t->data[j])
		{			
			i++;
			j++;
			continue;
		}
		j = nextval[j];
	}

	if( j >= tLen )
		return i - tLen;
	return -1;
}



int main() {
	SqString *s = new SqString();
	SqString *t = new SqString();
	char* strs = "World,Hello!";
	char* strt = "He";
	StrAssign(s, strs);
	StrAssign(t, strt);

	std::cout << KMPIndex(s, t) << std::endl;

	
}

