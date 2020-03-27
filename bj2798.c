#include <stdio.h>

int max(int a, int b)
{
	if ( a >= b ) return a;
	else return b;
}

int blackjack(int n, int m, int *card)
{
	int sum = 0;
	int goal = 0;
	int i = 0;
	int j = 1;
	int k = 2;

	while ( i < n )
	{
		j = i+1;
		while ( j < n )
		{
			k = j+1;
			while( k < n )
			{
				sum = card[i]+card[j]+card[k];
				if( m - sum >= 0 ) goal = max(sum, goal);
				k++;
			}
			j++;
		}
		i++;
	}

	return goal;
}

int main(void)
{
	int n, m;
	int i = 0;
	int goal = 0;

	fscanf(stdin, "%d %d", &n, &m);

	int card[n];
	while ( i < n )
	{
		fscanf(stdin, "%d", &card[i]);
		i++;
	}

	goal = blackjack(n, m, card);
	fprintf(stdout, "%d\n", goal);

	return 0;
}



