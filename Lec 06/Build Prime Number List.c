#include<stdio.h>

int main ()
{
	int i,j,ini,end;
	scanf("%d %d", &ini, &end);
	for(i=ini;i <= end;i++)
	{
		if(i == 2) printf("2 ");
		for(j=2;j < i;j++)
		{
			if(i%j == 0) break;
			if(j == i-1) printf("%d ",i);
		}
	}
	return 0;
}
