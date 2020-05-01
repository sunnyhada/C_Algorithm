#include <stdio.h>
#include <string.h>

char arr[6000][6000];

void star(int y, int x, int num)
{
	if(num==1)
	{
		arr[y][x]='*';
		return;
	}

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(i==1&&j==1) continue;
			else star(y+(i*(num/3)), x+(j*num/3), num/3);
		}
	}
}

int main(void)
{
	int num;
	scanf("%d", &num);

	memset(arr,' ',sizeof(arr));

	star(0,0,num);
	
	for(int i =0; i<num; i++)
	{
		for(int j=0; j<num; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
