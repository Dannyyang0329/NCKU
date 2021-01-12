#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 5

struct CARDS
{
    int rank;
    int suit;
} card[ROW][COL];

int compare(const void *a, const void *b)
{
	if( ((struct CARDS *)a)->rank == ((struct CARDS *)b)->rank ) return  ((struct CARDS *)a)->suit - ((struct CARDS *)b)->suit;
  	return ((struct CARDS *)a)->rank - ((struct CARDS *)b)->rank;
}

int straight(int n, struct CARDS card[ROW][COL])
{
	for(int i=0;i<COL-1;i++) if( (card[n][i+1].rank - card[n][i].rank) != 1) return 0; 
	return 1;
}

int flush(int n, struct CARDS card[ROW][COL])
{
	for(int i=0;i<COL-1;i++) if( (card[n][i+1].suit != card[n][i].suit) ) return 0; 
	return 1;
}

int four_of_a_kind(int n, struct CARDS card[ROW][COL])
{
	for(int i=1;i<COL-2;i++) if( (card[n][i+1].rank != card[n][i].rank) ) return 0; 
	return ( (card[n][0].rank==card[n][1].rank) || (card[n][4].rank==card[n][1].rank) ) ? 1 : 0;
}

int three_of_a_kind(int n, struct CARDS card[ROW][COL])
{
	if( (card[n][0].rank==card[n][1].rank) && (card[n][1].rank==card[n][2].rank) ) return 1;
	if( (card[n][1].rank==card[n][2].rank) && (card[n][2].rank==card[n][3].rank) ) return 1;
	if( (card[n][2].rank==card[n][3].rank) && (card[n][3].rank==card[n][4].rank) ) return 1;
	return 0;	
}

int fullhouse(int n, struct CARDS card[ROW][COL])
{
	if( (card[n][0].rank==card[n][1].rank && card[n][1].rank==card[n][2].rank) && (card[n][3].rank==card[n][4].rank) ) return 2;
	if( (card[n][1].rank==card[n][2].rank && card[n][2].rank==card[n][3].rank) && (card[n][0].rank==card[n][4].rank) ) return 3;
	if( (card[n][2].rank==card[n][3].rank && card[n][3].rank==card[n][4].rank) && (card[n][0].rank==card[n][1].rank) ) return 4;
	return 0;	
}

int two_pair(int n, struct CARDS card[ROW][COL])
{
	if( card[n][1].rank==card[n][2].rank && card[n][3].rank==card[n][4].rank ) return (card[n][2].rank > card[n][4].rank) ? 2 : 4;
	if( card[n][0].rank==card[n][1].rank && card[n][3].rank==card[n][4].rank ) return (card[n][1].rank > card[n][4].rank) ? 1 : 4;
	if( card[n][0].rank==card[n][1].rank && card[n][2].rank==card[n][3].rank ) return (card[n][1].rank > card[n][3].rank) ? 1 : 3;
	return 0;
}

int pair(int n, struct CARDS card[ROW][COL])
{
	for(int i=0;i<COL-1;i++)
		for(int j=i+1;j<COL;j++) if(card[n][i].rank==card[n][j].rank) return j;
	return 0;
}

int main(void)
{
    char Rank[ROW][COL], Suit[ROW][COL];
    int win[ROW]={0};  
    
    for(int i=0;i<ROW;i++)
    {
     	for(int j=0;j<COL;j++)
	{
            if(j != COL) scanf("%c%c ", &Rank[i][j], &Suit[i][j]);
            else scanf("%c%c\n", &Rank[i][j], &Suit[i][j]);

            switch(Rank[i][j])
	    {
                case 't': card[i][j].rank=10; break;
                case 'j': card[i][j].rank=11; break;
                case 'q': card[i][j].rank=12; break;
                case 'k': card[i][j].rank=13; break;
                case 'a': card[i][j].rank=14; break;
                default : card[i][j].rank = (Rank[i][j]-'0'); break;
            }          
            switch(Suit[i][j])
	    {
                case 'c': card[i][j].suit=1; break;
                case 'd': card[i][j].suit=2; break;
                case 'h': card[i][j].suit=3; break;
                case 's': card[i][j].suit=4; break;
            }
        }

        qsort(card[i], COL, sizeof(struct CARDS), compare);
        
	if( straight(i, card)==1 && flush(i, card)==1 ) win[i] = 9000 + 10*card[i][4].rank + card[i][4].suit;
	else if ( four_of_a_kind(i, card)==1 ) win[i] = 8000 + 10*card[i][2].rank;
	else if ( fullhouse(i, card) > 0 ) win[i] = 7000 + 10*card[i][fullhouse(i, card)].rank;
	else if ( flush(i, card) == 1 ) win[i] = 6000 + 10*card[i][4].rank + card[i][4].suit;
	else if ( straight(i, card) == 1 ) win[i] = 5000 + 10*card[i][4].rank + card[i][4].suit;
	else if ( three_of_a_kind(i, card) == 1 ) win[i] = 4000 + 10*card[i][2].rank;
	else if ( two_pair(i, card) > 0 ) win[i] = 3000 + 10*card[i][two_pair(i, card)].rank + card[i][two_pair(i, card)].suit;
	else if ( pair(i, card) > 0 ) win[i] = 2000 + 10*card[i][pair(i, card)].rank + card[i][pair(i, card)].suit;
	else win[i] = 1000 + 10*card[i][4].rank + card[i][4].suit;
    }
    
    char prt[4]={'A', 'B', 'C', 'D'};

    for(int i=0;i<ROW-1;i++)
    {
	for(int j=i+1;j<ROW;j++)
	{
		if ( win[j] < win[i] ) 
		{
			win[j] ^= win[i] ^= win[j] ^= win[i];
			prt[j] ^= prt[i] ^= prt[j] ^= prt[i];
		}
	}
    }

    for(int i=ROW-1;i>=0;i--) printf("%c ", prt[i]);

    return 0;
}
