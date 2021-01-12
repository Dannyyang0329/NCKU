int cmp(const void* a, const void* b) 
{
    int a_num = 60*(((struct message_info *)a)->time).hour + (((struct message_info *)a)->time).minute;
    int b_num = 60*(((struct message_info *)b)->time).hour + (((struct message_info *)b)->time).minute;
    return a_num-b_num;
}

void sort_message(struct message_info *m, int *total)
{
    qsort(m,*total,sizeof(struct message_info),cmp);
}