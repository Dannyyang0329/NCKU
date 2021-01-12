void star(int* arr, int* result)			//equal to (int arr[], int* result)
{		
	*result=0;					//initialize the value of result
	
	for(int i=0;i<5;i++) *result += arr[i];		
}
