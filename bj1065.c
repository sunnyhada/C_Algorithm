#include <stdio.h>

int hansu(int n)
{
	int hund, ten, one;
	int i=100;
	int cnt;

	if (n<100) cnt = n;
	
	else{
		
		cnt = 99;

		while (i<=n)
		{				
			hund = i/100;
			ten = (i%100)/10;
			one = i%10;

			if(hund-ten == ten-one) cnt++;

			i++;
		}

	}

	return cnt;
}

int main(void)
{
	int n;

	fscanf(stdin, "%d", &n);
	fprintf(stdout, "%d\n", hansu(n));

	return 0;
}
	
