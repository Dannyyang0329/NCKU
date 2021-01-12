#include<stdio.h>
#include<stdlib.h>

struct num
{
	int value;
	struct num *next;
	struct num *before;
};

int main()
{
	int number, select;
	scanf("%d %d", &number, &select);

	struct num *init=(struct num *) malloc( sizeof(struct num) ), *start=init;
	init->value = 1;
	init->next = NULL;
	init->before = NULL;

	for(int i=2;i<=number;i++)
	{
		struct num *tmp = (struct num *) malloc( sizeof(struct num) );
        
		tmp->value = i;
		tmp->before = init;

		if(i == number)
		{
			tmp->next = start;
			start->before = tmp;
		}	
		else tmp->next = NULL;

        init->next = tmp;
		init = init->next;
	}
	
	for(int i=0;i<select;i++)
	{
		printf("%d ", start->value);

		start->next->before = (start->before);
		start->before->next = start->next;

		start = start->next->next;
	}
	return 0;
}
