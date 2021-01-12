#include<stdio.h>

int C(int n, int m)
{
	if(m==0 || m==n) return 1;
	return C(n-1,m-1)+C(n-1,m);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", C(n,m));

	return 0;
}
