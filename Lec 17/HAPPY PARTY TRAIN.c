int fire(struct Car* head) 
{
	for(int i=0;;i++)
    {
        head = head->next;
     	if(head->passenger >= head->flammable) return i;
        if(head->next) head->next->passenger += head->passenger;
        else return i+1;
    }
}

