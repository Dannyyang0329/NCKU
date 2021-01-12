#include<stdio.h>

int A(int n, int m)
{
	if(n == 0) return m+1;
	if(m == 0) return A(n-1,1);
	return A(n-1,A(n,m-1));
}

int main ()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", A(n,m));

	return 0;
}
