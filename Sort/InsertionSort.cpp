/**
 * Insertioin sort (stable):
 * Best: T=O(N), Worst: T=O(N^2), extra S = O(1)
 *
 * Actually: T(N,I) = O(N+I) (I for inversion(s)),
 * average number of inversions in N different elements: N*(N-1)/4, 
 * so average time complexity: T=Ω(N^2)
 */
void InsertionSort(ElementType A[], int N)
{
	int P, i;
	ElementType Tmp;

	for (P = 1; P < N; P++) {
		Tmp = A[P];		/* Get the first element of the unsorted */
		for (i = P; i>=1 && A[i-1]>Tmp; i--)
			A[i] = A[i-1];	/* Right shift */
		A[i] = Tmp;		/* Put it in the right place */
	}
}

