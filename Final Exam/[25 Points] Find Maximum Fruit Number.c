void find_fruit(char input[],char fruit[][15])
{
    int cnt[20]={0};

    char *s = strtok(input,"+_+");
    
    while(s != NULL)
    {
        for(int i=0;i<20;i++) if(strcmp(s,fruit[i]) == 0) cnt[i]++;
        s = strtok(NULL,"+_+");
    }

    int max=cnt[0];
    for(int i=0;i<20;i++) max = (cnt[i]>max) ? cnt[i] : max;

    for(int i=0;i<20;i++) if(cnt[i] == max) printf("%s\n", fruit[i]);
}