void spread(char* graph, int row, int col)				// graph[8][8]
{
	char point=*(graph+8*row+col);

	for(int i=row-1;i >= 0;i--)					// UP
	{
		if(*(graph+8*i+col) == 'X') *(graph+8*i+col) = point;	
		if(*(graph+8*i+col) == point) continue;
		else break;	
	}

	for(int i=row+1;i < 5;i++)					// DOWN
	{
		if(*(graph+8*i+col) == 'X') *(graph+8*i+col) = point;
		if(*(graph+8*i+col) == point) continue;
		else break;
	}

	for(int i=col-1;i >= 0;i--)					// LEFT
	{
		if(*(graph+8*row+i) == 'X') *(graph+8*row+i) = point;
		if(*(graph+8*row+i) == point) continue;
		else break;
	}

	for(int i=col+1;i < 8;i++)					// RIGHT
	{
		if(*(graph+8*row+i) == 'X') *(graph+8*row+i) = point;
		if(*(graph+8*row+i) == point) continue;
		else break;
	}
}
