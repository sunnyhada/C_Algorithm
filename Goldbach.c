#include <stdio.h>

int makePrime(int num, int *Prime, int *numofPrime)
{
	int i = 1;
	int j = 2;
	
	int cnt = 0;

	while( i < num )
	{
		j = 2;
		while(j <= i)
		{
			if(i%j==0) break;
			j++;
		}
		if(i == j)
		{
			Prime[cnt] = i;
			cnt ++;
		}
		i++;
	}

	*numofPrime = cnt + 1;

	return 0;
}	

int Goldbach(int *Prime, int numofPrime, int num, int *a, int *b)
{
	int i = numofPrime/2;
	int j = numofPrime/2;

	while(i < numofPrime )
	{
		j = numofPrime/2;
		while( j >= 0 )
		{
			if(Prime[i] + Prime[j] == num)
			{
				*a = j;
				*b = i;
				return 0;
			}
			j--;
		}
		i++;
	}

	return 0;
}

int main(void)
{
	int T;
	int i = 0;
	int Prime[1000];

	int num;
	int numofPrime;
	int a, b;

	fscanf(stdin, "%d", &T);

	while(i<T)
	{
		fscanf(stdin, "%d", &num);
		makePrime(num, Prime, &numofPrime);
		Goldbach(Prime, numofPrime, num, &a, &b);
		fprintf(stdout, "%d %d\n", Prime[a], Prime[b]);
		
		i++;
	}

	return 0;
}
