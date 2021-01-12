#include<stdio.h>

int main ()
{
	int a,b,c,med;
	scanf("%d %d %d",&a,&b,&c);
	med = a;
	if( (a<=b && b<=c) || (c<=b && b<=a) ) med = b;
	if( (a<=c && c<=b) || (b<=c && c<=a) ) med = c;
	printf("%d", med);
	return 0;
}
