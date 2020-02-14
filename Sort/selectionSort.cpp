/**
 * Selection sort:
 * Worst: Tw = O(N^2) when using simple traverse search
 * extra S = O(1)
 * can be optimised by using minheap technique(Tw=N*logN)
 */
int ScanForMin(ElementType A[], int Left, int Right) {
	ElementType Min;
	int i, p;
	Min = A[Left];
	for (i = Left; i <= Right; i++)
		if (Min > A[i]) {
			Min = A[i];
			p = i;
		}
	return p;
}
void SelectionSort(ElementType A[], int N) {
	int i, MinPosition;
	for (i = 0; i < N; i++) {
		MinPosition = ScanForMin(A, i, N-1);
		Swap(A[i], A[MinPosition]);
	}
}
