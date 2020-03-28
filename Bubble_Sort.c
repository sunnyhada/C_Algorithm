#include <stdio.h>

int BubbleSort(int *arr, int arrlen)
{
	int i = 0;
	int j = 0;
	int temp;

	while( i < arrlen )
	{
		j = 1;
		while ( j < arrlen)
		{	
			if (arr[j-1] > arr[j])
			{	
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
			j++;
		}
		i++;
	}

	return 0;
}

void PrintArr(int *arr, int arrlen)
{
	int i = 0;

	while(i<arrlen)
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

	BubbleSort(arr, num);
	PrintArr(arr, num);

	return 0;
}
