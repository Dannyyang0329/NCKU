#include<stdio.h>
	
void y(int);									//give year determine ordinary(28) or leaf(29)
int first(int,int);								//give year and month to know that day is Sunday,Monday.......
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};				//let year is ordinary

int main ()
{
	int i,year,month,firstday;
	scanf("%d %d",&year,&month);

	firstday = first(year,month);
	y(year);

	printf("Sun Mon Tue Wed Thu Fri Sat \n");
	for(i=0;i<firstday;i++) printf("    ");
	for(i=1;i <= day[month-1];i++)
	{
		printf("%3d ",i);
		if( (i+firstday)%7==0 && i!=day[month-1]) printf("\n");		//No new line in the end
	}
	return 0;
}

void y(int num)									//determine February is 29 or 28
{
	int Day;								//ordinary (0) , leaf (1)
	if(num % 4 != 0) Day=0;
	if(num%100 == 0 && num%400 != 0) Day=0;
	if(num % 400 == 0) Day=1;
	if(num % 4 == 0) Day=1;

	if(Day == 1) day[1]=29;	
	else day[1]=28;
}

int first(int year,int month)							//To print the calendar we need to know the first day in that month
{
	int i=2020,j=0,mon=month,first=3;					//Let we know 2020/1/1 is Wendesday ( first=3 )
	if(year >= 2020)
	{
		for(i=2020;i <= year;i++)
		{
			y(i);							//Know that year's february is 28 or 29
			month = (i==year) ? mon-1 : 12 ;
			for(j=0;j < month ;j++) first += day[j];
		}
	}

	if(year < 2020)
	{
		for(i=2020-1;i >= year;i--)
                {       
			y(i);							//Know that year's february is 28 or 29
			month = (i==year) ? mon-1 : 0 ;
                        for(j=11;j >= month ;j--) first += day[j];
		}  
	}

	if(year >= 2020) return first%7;
	else if ( (first-3)%7>3) return 10-(first-3)%7;
       	     else return 3-(first-3)%7;
}
