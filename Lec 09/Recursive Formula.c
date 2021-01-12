#include<stdio.h>

int f(int x1, int x2, int n)
{
	if(n == 1) return x1;
	if(n == 2) return x2;

	return f(x1,x2,n-1)+f(x1,x2,n-2);
}

int main ()
{
	int x1, x2, n;
	while( ~scanf("%d %d %d", &x1, &x2, &n) ) 
	{
		if(n >= 3) printf("%d\n", f(x1, x2, n));
	}	

	return 0;
}
