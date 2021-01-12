#include<stdio.h>
#include<string.h>

int main ()
{
	int n;
	scanf("%d", &n);

	int m[n+1][n+1], x, y;
	memset(m,0,sizeof(m));
	
	for(int i=1;i<=n*n;i++)
	{
		if(i == 1) 
		{
			x=1, y=n/2+1;
			m[x][y] = 1;
			continue;
		}

		if(x-1<1) x = x-1+n;
		else x--;
                if(y+1>n) y = y+1-n;
		else y++;
		
		if(m[x][y] == 0) m[x][y] = i;
		else 
		{
			if(x+2<=n) x += 2;
			else x += (2-n);
			if(y-1>=1) y--;
			else y = y-1+n;
			m[x][y] = i;
			continue;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}

	return 0;
}
