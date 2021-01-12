#include<stdio.h>
#include<stdlib.h>

#define MAX_N 100

int compare(const void* a, const void* b)
{
    return *(char *)a - *(char*)b;
}

void f(char word[], int begin, int end, int total, char ans[])
{
    
    if(end == 0) 
    {
        for(int i=0;i<total;i++)
        {
            for(int m=0;m<total;m++)
                for(int n=m+1;n<total;n++) if(ans[m] == ans[n]) return;

            printf("%c", ans[i]);
            if(i == total-1) puts("");
        }
        return;
    }

    for(int i=0;i<total;i++)
    {
        ans[begin] = word[i];
        f(word,begin+1,end-1,total,ans);
    }
}

int main ()
{
    int cnt=0;
    char word[MAX_N], ans[MAX_N];

    while( scanf("%c", &word[cnt]) != EOF ) cnt++;
    qsort(word, cnt-1, sizeof(char), compare);
    f(word,0,cnt-1,cnt-1,ans);
}