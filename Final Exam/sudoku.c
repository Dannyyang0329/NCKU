#include<stdio.h>
#include<string.h>

#define ROW 9
#define COL 9

char map[ROW][COL];

int check(char map[ROW][COL], int x, int y)                                                                // check; '0' is ERROR , '1' is CORRECT
{
    for(int i=0;i<ROW;i++) if(map[x][y]!='*' && map[x][y]==map[i][y] && x!=i) return 0;                    // check row
    for(int i=0;i<COL;i++) if(map[x][y]!='*' && map[x][y]==map[x][i] && y!=i) return 0;                    // check col
    
    for(int i=(x/3)*3;i<((x/3)*3)+3;i++)                                                                   // check square
        for(int j=(y/3)*3;j<((y/3)*3)+3;j++)
            if(map[x][y]!='*' && map[x][y]==map[i][j] && (x!=i && y!=j)) return 0;

    return 1;
}

int putNum(char map[ROW][COL], int x, int y)
{
    if(map[x][y] != '*')                                                                                   // the original number in the map (can't be changed)
    {
        if(y+1 < COL) {if(putNum(map, x, y+1) == 1) return 1;}                                             
        else if(x+1 < ROW) {if(putNum(map, x+1, 0) == 1) return 1;}
        else return 1;
    }

    else
    {
        for(int n=1;n<=9;n++)
        {
            map[x][y] = n+'0';

            if( check(map, x, y)==1  )
            {
                if(y+1 < COL) { if(putNum(map, x, y+1) == 1) return 1; } 
                else if(x+1 < ROW) { if(putNum(map, x+1, 0) == 1) return 1; }
                else return 1;
            }
        }

        map[x][y] = '*';
    }

    return 0;
}

void printMap(char map[ROW][COL])                                                                          // print the map
{
    puts("");
    for(int i=0;i<ROW;i++)  
    {
        for(int j=0;j<COL;j++) printf("%c ", map[i][j]);
        puts("");
    }
}

int main ()
{
    memset(map,'*',ROW*COL);                                                                               // initial the map be '*'

    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++) scanf(" %c", &map[i][j]);                                                   // input the map

    if(putNum(map, 0, 0) == 1) printMap(map);                                                              // print the result if possible
    else printf("It's impossible!");                                                                       // if impossible
}