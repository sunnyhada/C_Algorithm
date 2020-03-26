#include <stdio.h>

int min_hanoi(int n)
{
	if ( n == 1 ) return 1;
	return 1+min_hanoi(n-1)*2;
}

void route_hanoi(int n, int a, int b, int c)
{
	if ( n == 1 ) fprintf(stdout, "%d %d\n", a, c);
	else
	{	
		route_hanoi(n-1, a, c, b);
		route_hanoi(1, a, b, c);
		route_hanoi(n-1, b, a, c);
	}
}

int main(void)
{
	int n = 0;
	int min = 0;

	fscanf(stdin, "%d", &n);

	fprintf(stdout, "%d\n", min_hanoi(n));

	route_hanoi(n, 1, 2, 3);

	return 0;
}
