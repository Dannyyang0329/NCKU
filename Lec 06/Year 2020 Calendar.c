#include<stdio.h>

int main ()
{
	int i,month,first=3,day[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	scanf("%d", &month);
	for(i=1;i < month;i++) first += day[i-1] , first %= 7; 

	printf("Sun Mon Tue Wed Thu Fri Sat \n");
	for(i=0;i < first;i++) printf("    ");
	for(i=1;i <= day[month-1];i++)
	{
		printf("%3d ",i);
		if( (first+i)%7 == 0 && i != day[month-1]) printf("\n");
	}
	return 0;
}
