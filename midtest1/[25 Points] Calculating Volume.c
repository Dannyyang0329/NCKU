#include<stdio.h>
#include<math.h>

int main()
{
	int mode;
	scanf("%d", &mode);

	if(mode == 1)
	{
		double length;
		scanf("%lf", &length);
		printf("%.2lf", length*length*length);
	}

	if(mode == 2)
	{
		double length, width, height;
		scanf("%lf %lf %lf", &length, &width, &height);
		printf("%.2lf", length*width*height);
	}
	if(mode == 3)
	{
		double radius, height;
		scanf("%lf %lf", &radius, &height);
		printf("%.2lf", 3.14*radius*radius*height);
	}
	if(mode == 4) 
	{
		double length;
		scanf("%lf", &length);
		printf("%.2lf", sqrt(2)*length*length*length/12);
	}

	return 0;
}
