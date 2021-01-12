void find_fruit(char input[],char fruit[][15])
{
    int cnt[20]={0};                                                        // cnt用來計每個水果數量 初始化為0(剛開始每個水果都0個)

    char *s = strtok(input,"+_+");                                          // 初始化 這個s是第一個水果
    
    while(s != NULL)                                                        // 一直執行直到沒有水果
    {
        for(int i=0;i<20;i++) if(strcmp(s,fruit[i]) == 0) cnt[i]++;         // 判斷s是20個水果的哪一個 並且加1
        s = strtok(NULL,"+_+");                                             // 找下一個水果 如果找不到會迴傳NULL
    }

    int max=cnt[0];                                                         // 另一個新變數(最大值) 
    for(int i=0;i<20;i++) max = (cnt[i]>max) ? cnt[i] : max;                // 找所有水果中數目中最多為多少

    for(int i=0;i<20;i++) if(cnt[i] == max) printf("%s\n", fruit[i]);       // 將數目最多的水果印出來
}