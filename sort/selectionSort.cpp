/**
 * Selection sort:
 * Worst: Tw = O(N^2) when using simple traverse search
 * extra S = O(1)
 * can be optimised by using minheap technique(Tw=N*logN)
 */
int ScanForMin(ElementType A[], int Left, int Right) {
	int p;
	ElementType Min = A[Left];
	for (int i = Left; i <= Right; i++)
		if (Min > A[i]) {
			Min = A[i];
			p = i;
		}
	return p;
}
void SelectionSort(ElementType A[], int N) {
	int MinPosition;
	for (int i = 0; i < N; i++) {
		MinPosition = ScanForMin(A, i, N-1);
		Swap(A[i], A[MinPosition]);
	}
}
