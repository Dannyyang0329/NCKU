#include<stdio.h>
#include<stdlib.h>

int compare(const void *a ,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int m[a+b];
	for(int i=0;i<a+b;i++) scanf("%d", &m[i]);

	qsort(m,a+b,sizeof(m[0]),compare);

	for(int i=0;i<a+b;i++) printf("%d ", m[i]);

	return 0;
}
