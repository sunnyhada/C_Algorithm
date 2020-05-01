#include <stdio.h>
#include <string.h>

char arr[8000][8000];

//세로, 가로, num
void star(int y, int x, int num)
{
	if(num==1)
	{
		arr[y][x]='*';
		return;
	}
	
	//별
	if(num==3)
	{
		arr[y][x+2]='*';
		arr[y+1][x+1]='*';
		arr[y+1][x+3]='*';
		arr[y+2][x]='*';
		arr[y+2][x+1]='*';
		arr[y+2][x+2]='*';
		arr[y+2][x+3]='*';
		arr[y+2][x+4]='*';
		return;
	}
	
	star(y,x,num/2);
	//왼쪽끝
	star(y+(num/2), x-(num/2), num/2);
	//오른쪽 끝
	star(y+(num/2), x+(num/2), num/2);
}



int main(void)
{
	int num;
	scanf("%d", &num);

	memset(arr,' ',sizeof(arr));
	
	star(0, num-3,num);

	for(int i=0; i<num; i++)
	{
		for(int j=0; j<2*num-1; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}

	return 0;
}
