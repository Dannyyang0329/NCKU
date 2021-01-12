#include<stdio.h>

int daycode(int);						//To find the first day of the year(mon,tus,wed......)
void y(int);							//To determind the year is ordinary(28) or leaf(29)
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main ()
{
	char *month[]=
	{
		"January\n",
		"Febrary\n",
		"March\n",
		"April\n",
		"May\n",
		"June\n",
		"July\n",
		"August\n",
		"September\n",
		"October\n",
		"November\n",
		"December\n"
	};
	int i,mon,year,dayf;
	printf("Please key in a year:");
	scanf("%d",&year);
	dayf = daycode(year);
	y(year);
	puts("\n\n");

	for(mon=1;mon <= 12;mon++)
	{
		printf("%s",month[mon-1]);
		printf("Sun Mon Tue Wed Thu Fri Sat \n");
		for(i=0;i<dayf;i++) printf("    ");
		for(i=1;i <= day[mon-1];i++)
		{
			printf("%3d ",i);
			if( (dayf+i) % 7 == 0 ) printf("\n");
		}
		dayf = (dayf+day[mon-1])%7;
		puts("\n");
	}
	return 0;
}

int daycode(int year)
{
	int a,b,c;
	a = (year-1) / 4;
	b = (year-1) / 100;
	c = (year-1) / 400;
	return (year+a-b+c) % 7;
}

void y(int year)
{
	if(year%4 == 0 && year%100 != 0  ||  year%400 == 0) day[1] = 29; 
	else day[1] = 28;
}	
