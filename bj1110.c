#include <stdio.h>

int Cycle(int N)
{
	int num=N;
	int cycle = 0;
	int sum;
	
	do
	{
		sum = num/10 + num%10;
		num = (num%10)*10 + sum%10;
		cycle++;
	}while(N!=num);

	return cycle;
}

int main(void)
{
	int N;
	int cycle;

	fscanf(stdin,"%d",&N);
	
	cycle = Cycle(N);

	fprintf(stdout, "%d\n", cycle);

	return 0;
}

