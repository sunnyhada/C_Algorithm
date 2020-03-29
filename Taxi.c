#include <stdio.h>

int Absolute(int a)
{
	if ( a >= 0 ) return a;
	else return -a;
}

int 

int Taxi(int x1, int y1, int x2, int y2)
{
	return Absolute(x1 - x2) + Absolute(y1 - y2);
