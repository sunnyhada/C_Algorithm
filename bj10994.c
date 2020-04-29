#include <stdio.h>

void Star(int len)
{
	for(int i = 0; i<len; i++)
	{
		if(i==0 || i == len-1) //맨 위&아래
			for(int j =0; j<len; j++) printf("*");
			
		else
		{
			if(i%2==1)
			{
				if(i<len/2)
				{
					for(int j=0; j<(i+1)/2; j++)
					{
						printf("*");
						printf(" ");
					}
					for(int j=0; j<len-4*(i/2+1);j++)
					{
						printf(" ");
					}
					for(int j=0; j<(i+1)/2; j++)
					{
						printf(" ");
						printf("*");
					}
				}

				else
				{
					for(int j=0; j<(len-i+1)/2; j++)
					{
						printf("*");
						printf(" ");
					}
					for(int j=0; j<(len-4*((len-i-1)/2+1));j++)
					{
						printf(" ");
					}
					for(int j=0; j<(len-i+1)/2; j++)
					{
						printf(" ");
						printf("*");
					}
				}
			}
			else
			{
				if(i<len/2+1)
				{
					for(int j=0; j<i/2; j++)
					{
						printf("*");
						printf(" ");
					}
					for(int j=0; j<len-4*(i/2);j++)
					{
						printf("*");
					}
					for(int j=0; j<(i+1)/2; j++)
					{
						printf(" ");
						printf("*");
					}
				}
				else
				{
					for(int j=0; j<(len-i)/2; j++)
					{
						printf("*");
						printf(" ");
					}
					for(int j=0; j<(len-4*((len-i-1)/2));j++)
					{
						printf("*");
					}
					for(int j=0; j<(len-i)/2; j++)
					{
						printf(" ");
						printf("*");
					}
				}
			}
		}
		printf("\n");
	}
}

int main(void)
{
	int num=0;
	scanf("%d", &num);

	int len = num*4-3;
	Star(len);
	return 0;
}
