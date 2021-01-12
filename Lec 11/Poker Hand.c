#include<stdio.h>
#define people 4
#define cards 5

void sort(int ranks[people+1][cards+1],int suits[people+1][cards+1], int person)
{
	for(int i=1;i<cards;i++)
    	{
       	        for(int j=i+1;j<=cards;j++)
       	        {
       	              if(ranks[person][j]<ranks[person][i]) 
		      {
			      ranks[person][j] ^= ranks[person][i] ^= ranks[person][j] ^= ranks[person][i];
			      suits[person][j] ^= suits[person][i] ^= suits[person][j] ^= suits[person][i];
		      }
       	        }
		for(int j=i+1;j<=cards;j++)
		{
			if(ranks[person][i]==ranks[person][j] && suits[person][j]<suits[person][i]) 
                              suits[person][j] ^= suits[person][i] ^= suits[person][j] ^= suits[person][i];
		}
   	}
}

int straight(int ranks[people+1][cards+1],int suits[people+1][cards+1], int person)
{	
	for(int i=1;i<cards;i++) if(ranks[person][i]+1 != ranks[person][i+1]) return 0;	
	return 1;
}

int flush(int suits[people+1][cards+1], int person)	
{
	for(int i=1;i<cards;i++) if(suits[person][i] != suits[person][i+1]) return 0;
	return 1;
}

int four_of_a_kind(int ranks[people+1][cards+1],int suits[people+1][cards+1], int person)
{
	if(ranks[person][2]==ranks[person][3] && ranks[person][3]==ranks[person][4])
		if(ranks[person][1]==ranks[person][2] || ranks[person][5]==ranks[person][2]) return 1;
	return 0;
}

int full_house(int ranks[people+1][cards+1],int suits[people+1][cards+1], int person)
{
	if(ranks[person][1]==ranks[person][2] && ranks[person][2]==ranks[person][3] && ranks[person][4]==ranks[person][5])
		return 1;
        if(ranks[person][3]==ranks[person][4] && ranks[person][4]==ranks[person][5] && ranks[person][1]==ranks[person][2])
		return 1;
	return 0;
}

int three_of_a_kind(int ranks[people+1][cards+1], int suits[people+1][cards+1], int person)
{
        if(ranks[person][1]==ranks[person][2] && ranks[person][2]==ranks[person][3])
		return 1;
        if(ranks[person][2]==ranks[person][3] && ranks[person][3]==ranks[person][4])
		return 1;
        if(ranks[person][3]==ranks[person][4] && ranks[person][4]==ranks[person][5])
		return 1;

	return 0;
}

int two_pair(int ranks[people+1][cards+1],int suits[people+1][cards+1], int person)
{
	if(ranks[person][1]==ranks[person][2] && ranks[person][3]==ranks[person][4]) return 1;
        if(ranks[person][2]==ranks[person][3] && ranks[person][4]==ranks[person][5]) return 2;
        if(ranks[person][1]==ranks[person][2] && ranks[person][4]==ranks[person][5]) return 3;

	return 0;
}

int pair(int ranks[people+1][cards+1],int suits[people+1][cards+1], int person)
{
	for(int i=1;i<people;i++)
		if(ranks[person][i] == ranks[person][i+1]) return i;
	
	return 0;	
}


int main()
{
	int ranks[people+1][cards+1], suits[people+1][cards+1];
	int ans[people+1]; 

	for(int i=1;i<=people;i++)
	{
		for(int j=1;j<=cards;j++)
		{
			char r, s;

			if(j!=cards) scanf("%c%c ", &r, &s);
			else scanf("%c%c\n", &r, &s);

			switch(r)
			{
				case 't': ranks[i][j] = 10;
				 break;
				case 'j': ranks[i][j] = 11;
				 break;
				case 'q': ranks[i][j] = 12;
				 break;
				case 'k': ranks[i][j] = 13;
				 break;
				case 'a': ranks[i][j] = 14;
			 	 break;
				default: ranks[i][j] = r-48;
				 break;
			}
			switch(s)
			{
                                case 'c': suits[i][j] = 1;
                                 break;
                                case 'd': suits[i][j] = 2;
                                 break;
                                case 'h': suits[i][j] = 3;
                                 break;
                                case 's': suits[i][j] = 4;
                                 break;
			}	
		}
		sort(ranks,suits,i);
	}


	for(int i=1;i<=people;i++)
	{
		if(straight(ranks,suits,i)==1 && flush(suits,i)==1) 			//straight flush
			ans[i] = 9000+10*ranks[i][5]+suits[i][5];

		else if(four_of_a_kind(ranks,suits,i) == 1)				//four-of-a-kind
			ans[i] = 8000+10*ranks[i][3];

		else if(full_house(ranks,suits,i) == 1)					//full-house
			ans[i] = 7000+10*ranks[i][3]+suits[i][3];

		else if(flush(suits,i) == 1) 						//flush
			ans[i] = 6000+10*ranks[i][5]+suits[i][5];
		

		else if(straight(ranks,suits,i) == 1)					//straight
			ans[i] = 5000+10*ranks[i][5]+suits[i][5];
		
		else if(three_of_a_kind(ranks,suits,i) == 1)				//three-of-a-kind
			ans[i] = 4000+10*ranks[i][3];

		else if(two_pair(ranks,suits,i) > 0)					//two-pair
		{
			int tmp=two_pair(ranks,suits,i);

			if(tmp == 1) 
				ans[i] = 3000+10*ranks[i][4]+suits[i][4];

			if(tmp==2 || tmp==3)
                        	ans[i] = 3000+10*ranks[i][5]+suits[i][5];
		}

		else if(pair(ranks,suits,i) > 0) 					//pair
		{
			int tmp=pair(ranks,suits,i);

			for(int k=1;k<=4;k++)
			{
				if(tmp == k) 
					ans[i] = 2000+10*ranks[i][k+1]+suits[i][k+1];
			}
		}

		else 
			ans[i] = 1000+10*ranks[i][5]+suits[i][5];
		
	}

	char print[5]={' ','A','B','C','D'};
	for(int i=1;i<people;i++)
	{
		for(int j=i+1;j<=people;j++)
		{
			if(ans[j] > ans[i])
			{
				ans[j] ^= ans[i] ^= ans[j] ^= ans[i];
				print[i] ^= print[j] ^= print[i] ^= print[j];
			}
		}
	}

	for(int i=1;i<=people;i++)
		printf("%c ", print[i]);

	return 0;
} 
