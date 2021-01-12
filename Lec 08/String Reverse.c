#include <stdio.h>

int main()
{
	int i=0, maxN;
	scanf("%d\n", &maxN);

	char s[maxN];
	while(i < maxN) scanf("%c", &s[i++]);
	while(i > 0) printf("%c", s[--i]);

	return 0;
}
