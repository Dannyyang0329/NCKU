#include<stdio.h>

int main ()
{
	int seat,move,who;
	scanf("%d %d %d",&seat,&move,&who);
	printf("%d", (who+move%seat)>=seat ? who+move%seat-seat : who+move%seat);
	return 0;
}
