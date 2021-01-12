#include<stdio.h>

int main ()
{
	int i,sum=0;
	char n[12];
	for(i=0;i < 12;i++) 
	{
		scanf(" %c",&n[i]);
		if(i%2 == 0) sum += n[i]-48;
		else sum += (n[i]-48)*3;
	}
	printf("%d", ((sum-1)/10+1)*10-sum );
	return 0;
}
