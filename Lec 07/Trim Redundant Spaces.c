#include<stdio.h>

int main ()
{
	char words[1000];
	scanf("%1000[^\n]",words);
	for(int i=0;words[i] != '\0';i++)
	{
		if(words[i]==' ' && words[i+1]!=' ') printf(" ");
		if(words[i]!=' ') printf("%c", words[i]);       	
	}
	return 0;
}
