#include<stdio.h>

int main ()
{
	int n, i, j, stop=0;
	scanf("%d", &n);

	int m[n][n];
	for(i=0;i < n;i++)
		for(j=0;j < n;j++) scanf("%d", &m[i][j]);

	for(i=0;i < n;i++)
		for(j=i+1;j < n;j++) 
			if(m[i][j]!=m[j][i]) stop=1;

	if(stop) printf("No\n");
	else printf("Yes\n");

	return 0;
}
