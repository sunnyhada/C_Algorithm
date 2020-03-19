#include <stdio.h>

void Alarm(int h, int m)
{
	if ( m<45 )
	{
		if ( h == 0)
			h = 24;
		h--;
		m += 15;
	}

	else
		m -= 45;

	fprintf(stdout, "%d %d\n", h, m);
}

int main(void)
{
	int h, m;

	fscanf(stdin, "%d %d", &h, &m);
	Alarm(h, m);

	return 0;
}
