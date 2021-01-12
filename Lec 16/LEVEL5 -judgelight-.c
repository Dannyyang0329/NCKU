/*
int cmp(const void *a, const void *b) 
{
	return *(int *)a-*(int *)b;
}
*/

#include<string.h>
void sort_level(struct ESPer *arr, int length) 
{
 	for(int i=0;i<length;i++)
	{
     		for(int j=i+1;j<length;j++)
        	{
         		if(arr[j].level < arr[i].level)
            		{
             	    		arr[j].level ^= arr[i].level ^= arr[j].level ^= arr[i].level;
 					
                		char tmp[70];
            	    		strcpy(tmp,arr[i].name);
                		strcpy(arr[i].name,arr[j].name);
                		strcpy(arr[j].name,tmp);
            		}
        	}
    	}
}

