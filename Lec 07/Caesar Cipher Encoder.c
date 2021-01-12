#include<stdio.h>

int main ()
{
	int move;
	char ch;

	scanf("%d%c", &move, &ch);
	move = (move<0) ? move%26+26 : move%26;

	while( scanf("%c", &ch) != EOF && ch!='\n') 
	{
		if(ch>='A' && ch<='Z') printf("%c",'A'+(ch-'A'+move)%26);
		else if(ch>='a' && ch<='z') printf("%c",'a'+(ch-'a'+move)%26);
		else printf("%c", ch);
	}
	return 0;
}
