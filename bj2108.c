#include <stdio.h>

void QuickSort(int *arr, int start, int end)
{
	if(start>=end)
	{
		return;
	}

	int pivot = start;
	int i = pivot+1;
	int j = end;
	int temp;

	while(i <= j){
		while(i<=end && arr[i] <= arr[pivot]) i++;
		while(j>start && arr[j] >= arr[pivot]) j--;

		if(i>j)
		{
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}

		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	QuickSort(arr, start, j-1);
	QuickSort(arr, j+1, end);
}



/*void SelectionSort(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int min;
	int temp = 0;

	while ( i < len-1 )
	{
		min = i;
		j = i+1;
		while ( j < len )
		{
			if(arr[min] > arr[j]) 
			{
				min = j;
			}
			j++;
		}

		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;

		i++;
	}
}
*/


//평균
/*
double Mean(int *arr, int len)
{
	double result = 0;
	int i = 0;
	while( i < len )
	{
		result += arr[i];
		i++;
	}

	result = result/len;

	return result;
}
*/

//중앙값
int Median(int *arr, int len)
{
	return arr[len/2];
}

//범위
int Range(int *arr, int len)
{
	return (arr[len-1] - arr[0]) ;
}

//최빈값
int Mode(int *arr, int len)
{
	int Mode[len];
	int i = 0;
	
	int temp = 0;
		
	int max = 0;
	int flag = 0;
	
	//초기화
	while(i<len)
	{
		Mode[i] = 0;
		i++;
	}
	

	//빈도수를 세서 저장
	i = 0;
	while(i<len)
	{
		if(arr[temp] == arr[i])
		{
			Mode[temp]++;
		}

		else
		{
			temp = i;
			Mode[temp]++;
		}
		i++;
	}

	//최빈값을 구함.
	i = 0;
	while(i<len)
	{
		if(Mode[i] > Mode[max])
		{
			max = i;
			flag = 1;
		}
		else if(Mode[i] == Mode[max] && flag == 0)
		{
			max = i;
			flag++;
		}
		else if(Mode[i] == Mode[max] && flag == 1)
		{
			max = i;
			flag++;
		}
		i++;
	}

	return arr[max];

}


int main(void)
{
	int N;

	double mean;
	int range;
	int mode;
	int median;

	fscanf(stdin, "%d", &N);

	int i = 0;
	int arr[N];

	while(i<N)
	{
		fscanf(stdin, "%d", &arr[i]);
		mean += arr[i];
		i++;
	}

	//SelectionSort(arr, N);

	QuickSort(arr, 0, N);

	mean = mean/N;
	median = Median(arr,N );
	range = Range(arr, N);
	mode = Mode(arr, N);

	fprintf(stdout, "%.0f\n", mean);
	fprintf(stdout, "%d\n", median);	
	fprintf(stdout, "%d\n", mode);	
	fprintf(stdout, "%d\n", range);	

	return 0;

}
