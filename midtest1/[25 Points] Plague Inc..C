#include<stdio.h>

int main ()
{
	double spread_speed, victim=1;
	int day;

	scanf("%lf %d", &spread_speed, &day);

	for(int i=1;i<=day;i++)	victim *= spread_speed;
	printf("%d", (int)victim);

	return 0;
}
