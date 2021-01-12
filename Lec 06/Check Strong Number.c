#include<stdio.h>
 
int factorial(int);

int main ()
{
	int number,num,sum=0;
	scanf("%d",&number);
	num = number;
	while(num != 0)
	{
		sum += factorial(num%10);	
		num /= 10;
	}
	if(number == sum) printf("%d is a strong number.",number);
	else printf("%d is not a strong number.",number);
}

int factorial(int num)
{
	int i,sum=1;
	for(i=1;i <= num;i++) sum *= i;
	return sum;
}
