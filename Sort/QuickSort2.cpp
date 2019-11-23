/**
 * Quick sort (unstable):
 * Average: Ta=O(NlogN), Worst: Tw=O(N^2), extra S=O(logN)
 * Note: It's important to pick up the pivot.
 */
ElementType Median3(ElementType A[], int Left, int Right)
{ 
	int Centre = (Left + Right)/2;
	
	if (A[Left] > A[Centre])
		Swap(&A[Left], &A[Centre]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Centre] > A[Right])
		Swap(&A[Centre], &A[Right]);
	
	/* A[Left] <= A[Centre] <= A[Right] */
	Swap(&A[Centre], &A[Right-1]);	/* Hide Pivot into A[Right-1] */

	/* Only need to consider A[Left+1] ... A[Right-2] */
	return A[Right-1];	/* Return Pivot */
}

/* The core recusive quick sort function */
void Qsort(ElementType A[], int Left, int Right)
{
	int Pivot, Cutoff, Low, High;

	/* If elements in sequence is quite enough, use quick sort, 
	 * otherwise use insertion sort (cause recursion need OS to allocate 
	 * extra space to finish it) choose your own Cufoff.
	 */
	Cutoff = 50; 	/* Cutoff should be positive */
	if (Cutoff < Right-Left) {
		Pivot = Median3(A, Left, Right);	/* Pick a pivot */ 
		Low = Left; High = Right-1;
		/* Move elements less than pivot to left part, others right part */
		for ( ; ; ) {
			while (A[++Low] < Pivot) ;
			while (A[--High] > Pivot) ;
			if (Low < High)
				Swap(&A[Low], &A[High]);
			else break;
		}
		Swap(&A[Low], &A[Right-1]);		/* Place pivot into the right place */ 
		Qsort(A, Left, Low-1);	/* Handle the left part recursively */ 
		Qsort(A, Low+1, Right);		/* Get the right part done recursively */  
	} else	/* Insufficient elements, using simple sort instead */
		InsertionSort(A+Left, Right-Left+1);
}

/* Unified interface */
void QuickSort(ElementType A[], int N)
{
	Qsort(A, 0, N-1);
}

