#include<stdio.h> 

int main ()
{
	int hour,minute;
	scanf("%d %d",&hour,&minute);
	minute = (minute>=10) ? hour++,minute-10 : minute+50 ;
	printf("%02d:%02d\n",hour,minute);
	return 0;
}
