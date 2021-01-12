#include<stdio.h>

int main ()
{
	int ha,hb,attack,tmp=0;
	scanf("%d %d", &ha, &hb);
	while(ha>0 && hb >0)
	{
		scanf("%d", &attack);
		if(tmp++ % 2 == 0) hb -= attack;
		else ha -= attack;
	}
	printf("%c", ha>0 ? 'A' : 'B');
	return 0;
}
