#include<stdio.h>
#define maxN 40

void swap(int a[], int x, int y)
{
	if(a[x] != a[y]) a[x] ^= a[y] ^= a[x] ^= a[y];
}

void quick(int a[], int left, int right)
{
	if(right > left)
	{
		int pivot=left, i=pivot+1, j=right;
		while(j > i)
		{
			while(i<=j && a[i]<a[pivot]) i++;
			while(a[j]>a[pivot]) j--;
			if(j > i) swap(a,i,j);
		}		
	        if(i >= j) swap(a,pivot,j);

		for(int k=1;k<=right;k++) printf("%d ", a[k]);
     		puts("");


		quick(a,j+1,right);
		quick(a,left,j-1);
	}
}


int main ()
{
	int i=1, a[maxN+1];
	while ( ~scanf("%d", &a[i]) ) i++;
	
	quick(a,1,i-1);

	for(int j=1;j<i;j++) printf("%d ", a[j]);
	puts("");

	return 0;
}
