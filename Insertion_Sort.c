#include <stdio.h>

int InsertionSort(int *arr, int arrlen)
{
	int i = 1;
	int j, key;

	while( i < arrlen )
	{
		key = arr[i];
		j = i-1;
		while ( j >= 0 && key < arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;
		i++;
	}

	return 0;

}

void PrintArr(int *arr, int arrlen)
{
	int i = 0;
	
	while( i < arrlen )
	{
		fprintf(stdout, "%d\n", arr[i]);
		i++;
	}

}

int main(void)
{
	int num;
	int i = 0;
	
	fscanf(stdin, "%d", &num);

	int arr[num];

	while(i<num)
	{
		fscanf(stdin, "%d", &arr[i]);
		i++;
	}

	InsertionSort(arr, num);

	PrintArr(arr, num);

	return 0;

}
