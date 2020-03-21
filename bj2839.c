#include <stdio.h>

int Sugar_min(int num)
{
	int f_cnt = num/5;

	if ( num % 5 == 0 ) 
		return num/5;

	while (f_cnt >= 0)
	{
		if ( (num - 5*f_cnt)%3 == 0 )
			return f_cnt + (num-5*f_cnt)/3 ;
		else if ( f_cnt == 0 && num%3 !=0 )
			return -1;
		else
			f_cnt --;
	}
}

int main(void)
{
	int num;
	int cnt;

	fscanf(stdin, "%d", &num);
	
	cnt = Sugar_min(num);

	fprintf(stdout, "%d\n", cnt);

	return 0;
}
