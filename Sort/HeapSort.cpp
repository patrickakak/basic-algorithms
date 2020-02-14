/**
 * Heap sort (unstable):
 * Worst: Tw = 2NlogN - O(NloglogN) (better than NlogN)
 * extra S = O(1)
 * suit for top K minimum or maximum elements selection
 * 
 * Note: but in fact, it's not that useful, Sedgewick sequence 
 * Shell sort normally is better.
 */
void PercDown(ElementType A[], int p, int N) {
	int Parent, Child;
	ElementType X;
	X = A[p];
	for (Parent = p; (Parent*2+1) < N; Parent = Child) {
		Child = 2*Parent + 1;
		if ((Child != N-1) && (A[Child] < A[Child+1])) Child++;
		if (X >= A[Child]) break;
		else A[Parent] = A[Child];
	}
	A[Parent] = X;
}
void HeapSort(ElementType A[], int N)  {
	int i;
	for (i = N/2-1; i >= 0; i--)
		PercDown(A, i, N);
	for (i = N-1; i > 0; i--) {
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}
