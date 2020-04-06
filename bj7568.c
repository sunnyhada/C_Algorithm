#include <stdio.h>

int BiggerLanking(int people[][2], int num, int *order)
{
	int i = 0;
	int j = 0;

	while ( i < num )
	{
		j = i+1;
		while(j < num)
		{
			if(people[i][0] > people[j][0])
			{
				if(people[i][1] > people[j][1])	order[j]++;
			}
			else if (people[i][0] < people[j][0])
			{
				if(people[i][1] < people[j][1]) order[i]++;
			}
			j++;
		}

		order[i] ++; /*순서이므로 k+1출력을 위해 1 더해주기*/
		i++;
	}

	return 0;
}

void PrintArr(int *arr, int arrlen)
{
	int i = 0;
	while ( i < arrlen )
	{
		fprintf(stdout, "%d ", arr[i]);
		i++;
	}
	fprintf(stdout, "\n");
}

int main(void)
{
	int N ; /*num of people*/

	fscanf(stdin, "%d", &N);

	int people[N][2];
	int i = 0;
	int order[50] = {0, };

	while ( i < N )
	{
		fscanf(stdin, "%d %d", &people[i][0], &people[i][1]);
		i++;
	}
	
	BiggerLanking(people, N, order);
	PrintArr(order, N);

	return 0;
}
