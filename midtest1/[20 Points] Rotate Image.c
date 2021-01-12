#include<stdio.h>

void trans(int , int, int, int (*m)[]);

int main ()
{
	int angle, column, row;
	scanf("%d", &angle);
	scanf("%d %d", &column, &row);

	int m[column+1][row+1];

	for(int i=1;i<=column;i++)
	{
		for(int j=1;j<=row;j++) scanf("%d", &m[i][j]);
	}

	trans(column,row,angle/90,m);

	return 0;
}


void trans(int column, int row, int time, int m[column+1][row+1])
{
	int rm[row+1][column+1];
	for(int i=1;i<=column;i++)
	{
		for(int j=1;j<=row;j++) rm[j][column-i+1] = m[i][j];
	}
	time--;

	if(time == 0)  
	{
		for(int i=1;i<=row;i++)
          	{       
        		for(int j=1;j<=column;j++) printf("%d ", rm[i][j]);
			printf("\n");
            	}
	}
	else trans(row,column,time,rm);
}
