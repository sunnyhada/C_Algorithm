#include <stdio.h>

double AboveAvg(int *arr, int arrlen, double avg)
{
	int i = 0;
	double cnt = 0;

	while(i<arrlen)
	{
		if(arr[i] > avg) cnt++;
		i++;
	}

	return cnt/arrlen*100;
}

int main(void)
{
	int Case;
	int score[1000];

	double avg = 0;

	int i = 0;
	int j = 0;

	int student;

	fscanf(stdin, "%d", &Case);

	while( i < Case )
	{
		j = 0;
		avg = 0;
		fscanf(stdin, "%d", &student);
		while( j < student )
		{
			fscanf(stdin, "%d", &score[j]);
			avg += (double)score[j]/(double)student;
			j++;
		}
		fprintf(stdout, "%.3f%%\n", AboveAvg(score, student, avg));
		i++;
	}

	return 0;
}
