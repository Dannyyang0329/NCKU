#include<stdio.h>

int main ()
{
	char rome[4][10][5] =
	{
		{"","I","II","III","IV","V","VI","VII","VIII","IX"},		
		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
	       	{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
		{"","M","MM","MMM"}	
	};

	int i,num,pout[4];
	scanf("%d",&num);
	for(i=0;i < 4;i++) 
	{
		pout[i] = num%10;
		num /= 10;
	}
	for(i=3;i >= 0;i--) printf("%s", rome[i][pout[i]]);
	return 0;
}


