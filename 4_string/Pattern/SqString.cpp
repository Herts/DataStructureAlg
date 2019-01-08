#define MAX_SIZE 250

struct SqString{
	char data[MAX_SIZE];
	int length;
};

void StrAssign(SqString *&s, char str[])
{
	int i = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		s->data[i] = str[i];
	}
	s->length = i;

}

void DestroyStr(SqString *&s)
{
}

void StrCopy(SqString *&s, SqString *t)
{
	int len = t->length;

	for(int i = 0; i < len; i++) {
		s->data[i] = t->data[i];
	}

	s->length = t->length;

}

bool StrEqual(SqString *s, SqString *t) {
	if(s->length != t->length) return false;

	int i = 0;
	int len = s->length;
	while(i < len)
	{
		if(s->data[i] != t->data[i])
			return false;
	}

	return true;
}

int StrLength( SqString *s) {
	return s->length;
}

SqString *Concat(SqString *s, SqString *t)
{
	SqString *str = new SqString();
	str->length = s->length + t->length;
	int sLen = s->length, tLen = t->length;

	for(int i = 0; i < sLen; i++)
	{
		str->data[i] = s->data[i];
	}
	for(int i = 0; i < tLen; i++)
	{
		str->data[sLen + i] = t->data[i];
	}

	return str;
}

SqString *SubStr(SqString *s, int i, int j)
{
	int k = 0;
	SqString *str = new SqString();
	str->length = 0;

	if( i < 0 || i >= s->length  || j > s->length || j < i )
		return str;

	for( k = i; k <= j; k++)
	{
		str->data[k] = s->data[i];
	}
	str->length = k;

	return str;
}

/* insert s2->data after s1->data[i-1] */
SqString *InsStr(SqString *&s1, SqString *s2, const int i)
{
	SqString *str = new SqString();
	str->length = 0;

	int s1Len = s1->length, s2Len = s2->length;
	if(i < 0 || i > s1->length)
		return str;
	
	for(int j = 0; j < i; j++)
	{
		str->data[j] = s1->data[i];
	}
	for(int j = 0; j < s2Len; j++)
	{
		str->data[i+j] = s2->data[j];
	}
	int strLen = i+s2Len;
	for(int j = i; j < s1Len; j++)
	{
		str->data[strLen+i] = s1->data[j];
	}

	str->length = s1Len + s2Len;

	return str;
}



