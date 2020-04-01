#include <stdio.h>

float AboveAvg(float *arr, float arrlen, float avg)
{
	int i = 0;
	float cnt = 0;

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
	float score[1000];

	float avg = 0;

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
			fscanf(stdin, "%f", &score[j]);
			avg += score[j]/student;
			j++;
		}
		fprintf(stdout, "%.3f%%\n", AboveAvg(score, student, avg));
		i++;
	}

	return 0;
}
