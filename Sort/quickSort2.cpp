/**
 * Quick sort (unstable):
 * Average: Ta=O(NlogN), Worst: Tw=O(N^2), extra S=O(logN)
 * Note: It's important to pick up the pivot.
 */
ElementType Median3(ElementType A[], int Left, int Right) {
	int Centre = (Left + Right)/2;
	if (A[Left] > A[Centre]) Swap(&A[Left], &A[Centre]);
	if (A[Left] > A[Right]) Swap(&A[Left], &A[Right]);
	if (A[Centre] > A[Right]) Swap(&A[Centre], &A[Right]);
	Swap(&A[Centre], &A[Right-1]);
	return A[Right-1];
}
void Qsort(ElementType A[], int Left, int Right) {
	int Pivot, Cutoff, Low, High;
	Cutoff = 50;
	if (Cutoff < Right-Left) {
		Pivot = Median3(A, Left, Right);
		Low = Left; High = Right-1;
		for ( ; ; ) {
			while (A[++Low] < Pivot) ;
			while (A[--High] > Pivot) ;
			if (Low < High) Swap(&A[Low], &A[High]);
			else break;
		}
		Swap(&A[Low], &A[Right-1]);
		Qsort(A, Left, Low-1);
		Qsort(A, Low+1, Right);
	} else insertionSort(A+Left, Right-Left+1);
}
void QuickSort(ElementType A[], int N) {
	Qsort(A, 0, N-1);
}
