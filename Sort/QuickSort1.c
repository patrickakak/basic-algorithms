/**
 * Quick sort (unstable):
 * Average Ta=O(NlogN), Worst: T=O(N^2), extra S=O(logN)
 * Call library function directly version 
 */
#include <stdlib.h>

/*--------------- Simple integer sort --------------------*/
int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
/* Call a function */ 
qsort(A, N, sizeof(int), compare);
/*--------------- Simple integer sort --------------------*/


/*--------------- In general, sort key in a struct Node out ---------------*/
struct Node {
	int key1, key2;
} A[MAXN];

/* Compare 2 keys: non-ascending order of key1; if key1s are equal, 
 * sort in non-descending order of key2 */
int compare2keys(const void *a, const void *b)
{
	int k;

	if (((const struct Node*)a)->key1 < ((const struct Node*)b)->key1)
		k = 1;
	else if (((const struct Node*)a)->key1 > ((const struct Node*)b)->key1)
		k = -1;
	else {	/* If key1s are the same */
		if (((const struct Node*)a)->key2 < ((const struct Node*)b)->key2)
			k = -1;
		else k = 1;
	}
	return k;
}
/* Call a function */ 
qsort(A, N, sizeof(struct Node), compare2keys);
/*--------------- In general, sort key in a struct Node out ---------------*/

