#include <stdio.h>
#include <math.h>

void isPrime(int *Prime, int size)
{
	int i = 2;
	int j;

	/* 에라토스 테네스의 체를 이용하여 소수판별
	   소수는 그대로 0, 소수가 아닌것은 1으로 */

	while( i < (int)sqrt(size) ) //총 배열의 크기의 루트값 만큼만 반복 시행
	{
		j = i*i;
		while( j <= size )
		{
			if(Prime[j] % i == 0) Prime[j] = 0;
			i + j;
		}
		i++;
	}

}

void GoldBach(int *Prime, int num)
{
	int i = num/2;
	/* 골드바흐는 2개의 수를 합한것이므로 num/2번째 부터 탐색 시작.
	   최소차를 출력하라 했으므로 num/2 부터 점차 배열의 처음으로 가면서 탐색. */

	while ( i > 0 )
	{
		if( Prime[i] != 1 && Prime[num - i] != 1 )
		{
			/*배열 자체가 모든 수를 가지고 있으므로 자기자신 = 배열의 순서가 됨*/
			fprintf(stdout, "%d %d\n", i, num-i); 
			break;
		}
	}
}

int main(void)
{
	/*총 수의 크기만큼을 배열로 만들기*/
	int Prime[100000] = { 0, }; 
	int T, num;
	int i = 0;

	isPrime(Prime, 100000);

	fscanf(stdin, "%d", &T);

	while( i < T )
	{
		fscanf(stdin, "%d", &num);
		GoldBach(Prime, num);
		i++;
	}

	return 0;
}
	

	
