/**
 * Insertioin sort (stable):
 * Best: T=O(N), Worst: T=O(N^2), extra S = O(1)
 *
 * Actually: T(N,I) = O(N+I) (I for inversion(s)),
 * average number of inversions in N different elements: N*(N-1)/4, 
 * so average time complexity: T=Ω(N^2)
 *
 * An array is partially-sorted if # of inversions <= c*N
 * For partially-sorted arrays, Insertion sort runs in linear time (i.e. O(N))
 */
void InsertionSort(ElementType A[], int N) {
	for (int P = 1; P < N; P++) {
		ElementType Tmp = A[P];
		int i;
		for (i = P; i>=1 && A[i-1]>Tmp; i--)
			A[i] = A[i-1];
		A[i] = Tmp;
	}
}
