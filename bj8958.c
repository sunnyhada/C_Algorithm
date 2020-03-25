#include <stdio.h>

int arr_sum(int *arr, int arrlen)
{
	int i = 0;
	int sum = 0;

	while(i<arrlen)
	{
		sum += arr[i];
		i++;
	}

	return sum;
}

int *score(char *arr, int arrlen, int *sum)
{
	int i = 0;

	while(i<arrlen)
	{
		if(arr[i] == 'O')
		{
			if(i==0) sum[i] = 1;
			else sum[i] = sum[i-1] + 1;
		}
		else sum[i] = 0;
		
		i++;
	}

	return sum;
}

int arr_len(char *arr)
{
	int len = 0;
	while(arr[len] != '\0')
	{
		len++;
	}

	return len;
}

int main(void)
{
	int cnt = 0;
	int i = 0;
	char str[80];
	int sum[80];

	fscanf(stdin, "%d", &cnt);
	
	while(i<cnt)
	{
		fscanf(stdin, "%s", str);
		fprintf(stdout, "%d\n", arr_sum(score(str, arr_len(str), sum), arr_len(str)));
		i++;
	}

	return 0;

}
