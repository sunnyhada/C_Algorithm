#include <stdio.h>

void Print_arr(int *arr, int len)
{
	int i = 0;

	while( i < len )
	{
		fprintf(stdout, "%d\n", arr[i]);
		i++;
	}
}

int *count(int num, int *arr)
{
	int cnt = 0;
	int i = 0;

	while ( num != 0 )
	{
		i = num%10;
		arr[i] += 1;
		num = num/10;
		cnt++;
	}

	return arr;
}

int main(void)
{
	int A, B, C;
	int arr[10] = {0,0,0,0,0,0,0,0,0,0};

	fscanf(stdin, "%d %d %d", &A, &B, &C);

	Print_arr(count(A*B*C, arr), 10);

	return 0;

}
