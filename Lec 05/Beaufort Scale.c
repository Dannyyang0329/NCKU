#include<stdio.h>

int main ()
{
	int speed;
	scanf("%d",&speed);
	if(speed < 1) printf("Calm");
	else if (speed <= 3) printf("Light air");
	else if (speed <= 27) printf("Breeze");
	else if (speed <= 47) printf("Gale");
	else if (speed <= 63) printf("Storm");
	else printf("Hurricane");
	return 0;
} 
