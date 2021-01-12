int search(dict_t arr[], char target[])
{
	for(int i=0;i<N;i++)
  	{
     		if(strcmp(arr[i].word,target) == 0) return arr[i].page;   
    	}

    	return 0;
}
