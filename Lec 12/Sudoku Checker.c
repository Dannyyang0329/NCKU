void check_sudoku(int (*grid_p)[NUM])									//equal to int grid_p[NUM][NUM}
{	
	for(int i=0;i<NUM;i++)										//scan all element
	{
		for(int j=0;j<NUM;j++)
		{
			int pt_once=0, element=grid_p[i][j];
			for(int k=0;k<NUM && pt_once==0;k++)						//row test
			{
				if(k == i) continue;
				if(element==grid_p[k][j]) printf("(%d,%d)\n", i, j), pt_once=1;
			}

			for(int k=0;k<NUM && pt_once==0;k++)						//column test
			{
				if(k == j) continue;
				if(element==grid_p[i][k]) printf("(%d,%d)\n", i, j), pt_once=1;
			}

			for(int m=3*(i/3);m<3*(i/3)+3 && pt_once==0;m++)				//square test
			{
				for(int n=3*(j/3);n<3*(j/3)+3 && pt_once==0;n++)
				{
					if(m==i && n==j) continue;
					if(element==grid_p[m][n]) printf("(%d,%d)\n", i, j), pt_once=1;
				}
			}
		}
	}
}
