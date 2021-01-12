int rising_hope(char *R) 
{
	int lucky=0;

	for(int i=0;i<strlen(R);i++)
	{
		if(R[i] == 'P') lucky++;
		if(R[i] == 'N') lucky--;
	}	

	return lucky;
}

