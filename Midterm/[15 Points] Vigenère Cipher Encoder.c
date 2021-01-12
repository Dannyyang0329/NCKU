#include<stdio.h>

int main()
{
	int words,  count=0;
	char ch;
	
	scanf("%d\n", &words);
	int key[words];

	for(int i=0;i<words;i++)
	{
		char tmp;
		scanf("%c", &tmp); 
		key[i] = tmp-'a';
	}
	scanf("%c", &ch);

	while( ~scanf("%c", &ch) && ch != '\n')
	{
		if(ch>='a' && ch<='z')
		{
			if(ch+key[count%words]>'z')
			{
				ch += (key[count%words]-26);
			}
			else ch += key[count%words];

			count++;
		}
		if(ch>='A' && ch<='Z')
		{
			if(ch+key[count%words]>'Z')
			{
				ch += (key[count%words]-26);
			}
			else ch += key[count%words];

			count++;
		}
		printf("%c", ch);
	}

	return 0;
}
