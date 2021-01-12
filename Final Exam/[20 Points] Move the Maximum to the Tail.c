void MoveToTail() {
    int max=head->val;
    
    struct node* run = (struct node*)malloc(sizeof(struct node));
    run = head;
    
    while(run->next != NULL)
    {
     	max = (run->val > max) ? run->val : max;
        run = run->next;
    }
    max = (run->val > max) ? run->val : max;
  
    
    struct node* find = (struct node*)malloc(sizeof(struct node));
    struct node* append = (struct node*)malloc(sizeof(struct node));    
    
    find = head;
    
    if(find->val == max) 
    {   
     	head = head->next;
        find = head;
        
        while(find->next != NULL) find = find->next;
    	
        find->next = append;
        append->next=NULL;
        append->val = max;
    }
    else
    {
        while(find->next->val != max) find = find->next;
        if(find->next->next != NULL)find->next = find->next->next;
        else return;
       
        if(find->next->next == NULL)
        {
            find = find->next;
            find->next = append;
            append->next=NULL;
            append->val = max;  
        }
        else
        {
            while(find->next != NULL) find=find->next;
            find->next = append;
            append->next=NULL;
            append->val = max; 
        }
    }
}