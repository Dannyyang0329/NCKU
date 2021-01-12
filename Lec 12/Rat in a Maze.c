// Todo: fill the route matrix with 0's or 1‘s.
// If there isn't any route, return false; otherwise, return true.


int n_again[5][5];							// To determine it has calculated or not					
const int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };			// UP-DOWN-LEFT-RIGHT
 
bool visit(char maze[][n], int route[][n], int originX, int originY) 
{
	n_again[originX][originY] = 1;
	route[originX][originY] = 1;

	if(originX==4 && originY==4) return true;			// Arrived at end

	for(int i=0;i<4;i++)						// Determine four directions
	{
		int moveX=originX+dir[i][0], moveY=originY+dir[i][1];

		if( (moveX>=0 && moveX<5) && (moveY>=0 && moveY<5) )	// Out map or not
		{
			if(n_again[moveX][moveY]==0 && maze[moveX][moveY]=='r' && visit(maze, route, moveX, moveY))
				return true;				// (*)
		}
	}

	route[originX][originY] = 0;					// If (*) doesn't execute, route[originX][originY] should be 0 

	return false;
}
/*	水水水~~    */
