#include<stdio.h>

long double f(long double);

int main ()
{
	int m,n;
	scanf("%d %d", &m, &n);
	printf("%.0Lf",f(m)/(f(n)*f(m-n)));
	return 0;
}

long double f(long double num)
{
	long double sum=1;
	for(int i=1;i <= num;i++) sum *= i;
	return sum;
}	
