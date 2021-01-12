void push(struct head *stack_p, int data)     
{
	struct element *append = (struct element *) malloc( sizeof(struct element) );

	(append->data) = data;
       	(append->next) = NULL;

	if(!stack_p->size)
	{
		(stack_p->next) = append;
	       	(stack_p->top) = append;
	}	
	else 
	{
		(stack_p->top)->next = append;
	       	(stack_p->top) = append;
	}	
	
	(stack_p->size)++;
}

struct element* pop(struct head *stack_p)     
{
	struct element *ans = (stack_p->top);
	struct element *ftop = (stack_p->next);

	if( !(stack_p->size-1) )
	{
		(stack_p->next) = NULL;
		(stack_p->top) = NULL;
	}
	else
	{
		while(ftop->next != stack_p->top) ftop = (ftop->next);
		(ftop->next) = NULL;
		(stack_p->top) = ftop;	
	}

	(stack_p->size)--;

	return ans;
}
