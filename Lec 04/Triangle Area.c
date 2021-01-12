#include<stdio.h>
#include<math.h>

int main ()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	float s = 0.5*(a+b+c);
	printf("%.2f", sqrt(s*(s-a)*(s-b)*(s-c)) );
	return 0;
}
