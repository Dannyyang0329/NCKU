#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
	return ( *(int *)a - *(int *)b );	
}

int main ()
{
    int a[3];
   	for(int i=0;i<3;i++) scanf("%d", &a[i]);
    qsort(a,3,sizeof(int),compare);
    printf("%d", a[1]);
    return 0;
}
