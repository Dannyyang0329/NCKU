#include<stdio.h>

long B(long a)
{
	if(a <= 2) return 1;
	return (2*B(a-1)+3*B(a-2))%1000000007;
}

int main()
{
	int i;
	scanf("%d", &i);
	printf("%ld", B(i));

	return 0;
}
