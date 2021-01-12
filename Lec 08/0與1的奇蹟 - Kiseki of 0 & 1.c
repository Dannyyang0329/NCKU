#include<stdio.h>

int main()
{
	int i, a[32], b[32], c[32], tmp=0;
	for(i=0;i < 32;i++) scanf("%d", &a[i]);
	for(i=0;i < 32;i++) scanf("%d", &b[i]);

	for(i=31;i >= 0 ;i--)
	{
		c[i] = a[i]^b[i]^tmp;
		tmp = ( a[i]&b[i] || (a[i]^b[i])&tmp );
	}

	for(i=0;i < 32;i++) printf("%d ", c[i]);

	return 0;
}	
