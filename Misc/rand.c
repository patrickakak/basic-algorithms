/**
 * To get a random number
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;

	srand((unsigned) time(NULL));
    
    // Generate number in interval [10000, 60000]
	for (i = 0; i < 10; i++)
		printf("%d ", (int)(round(1.0*rand()/RAND_MAX*50000 + 10000)));
	putchar('\n');

	return 0;
}

