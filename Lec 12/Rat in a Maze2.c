bool visit(char maze[][n], int route[][n], int originX, int originY) 
{
	int dir[4][2]={ {1,0}, {0,1}, {-1,0}, {0,-1} };								// DOWN-RIGHT-UP-LEFT
														//   0    1    2   3
	int cnt=0;
	int chX=originX, chY=originY;
	route[0][0] = 1;
 
	while(1) 
	{
		cnt++;
	        int d=cnt%4;
            
		if(chX+dir[d][1]>=0 && chX+dir[d][1]<=4 && chY+dir[d][0]>=0 && chY+dir[d][0]<=4 && maze[chX+dir[d][1]][chY+dir[d][0]]=='r') 
		{
			chX += dir[d][1], chY += dir[d][0];

			if(route[chX][chY] == 1)
			{
				maze[chX-dir[d][1]][chY-dir[d][0]]='w';
				route[chX-dir[d][1]][chY-dir[d][0]]=0;
				cnt++;
				continue;
			}

        		route[chX][chY]=1;
			if(chX==4 && chY==4) return true;
			cnt += 2;
		}	
		if(maze[0][1]=='w' && maze[1][0]=='w') return false;
	}	
}
