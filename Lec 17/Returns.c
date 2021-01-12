int* Returns(int n) 
{
	int *out = malloc( n*sizeof(int) );

	for(int i=0;i<n;i++) *(out+i) = i*i;

	return out;
}

