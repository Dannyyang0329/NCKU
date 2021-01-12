#include<stdio.h>

int main ()
{
	int red, green, blue;
	scanf("#%2X%2X%2X", &red, &green , &blue);
	printf("rgb(%d,%d,%d)", red, green, blue);
	return 0;
}
