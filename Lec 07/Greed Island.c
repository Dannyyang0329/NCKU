#include<stdio.h>

int main ()
{
	char ch;
	for(int i=0;i < 20;i++)
	{
		scanf("%c", &ch);
		switch(ch)
		{
			case 'A':
				printf("C");
				break;
			case 'B':
				printf("R");
				break;
			case 'C':
				printf("W");
				break;
			case 'D':
				printf("Z");
				break;
			case 'E':
				printf("G");
				break;
		}	
	}
	return 0;
}
