int addition(char str[])
{
	int num=0, sum=0;

	for(int i=0;i<strlen(str);i++)
	{
		if(str[i] != '+') num = num*10 + (str[i]-'0');
		else sum += num, num=0;
	}

	return sum+num;
}
