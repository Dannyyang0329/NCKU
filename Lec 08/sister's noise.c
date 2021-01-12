#include<stdio.h>

int main ()
{
	int f[10], max=0, noise;
	for(int i=0;i < 10;i++) scanf("%d", &f[i]);
	
	for(int i=0;i < 9;i++)
		for(int j=i+1;j < 10;j++)
		{
			noise = (f[i]+f[j])*(j-i);
			max = (noise > max) ? noise : max;
		}

	printf("%d", max);

	return 0;
}
