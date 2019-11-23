/**
 * Bubble sort (stable):
 * Best: T=O(N), Worst: T=O(N^2), could handle linkedlist
 * extra S = O(1)
 */
void BubbleSort(ElementType A[], int N)
{
	int P, i, flag;		/* flag: to indicate a already ordered sequence */

	for (P = N-1; P >= 0; P--) {
		flag = 0;
		for (i = 0; i < P; i++)		/* One single bubble sort */
			if (A[i] > A[i+1]) {	/* Stable */
				Swap(A[i], A[i+1]);
				flag = 1;	/* To indicate a swap */
			}
		if (flag == 0) break;	/* There's no swap */
	}
}

