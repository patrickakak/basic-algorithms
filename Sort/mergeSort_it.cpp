/**
 * Merge sort (stable): Iterative version
 * Worst: Tw = O(NlogN), usually be used as a way of external sort
 * extra S = O(N)
 */

/* Don't need to copy ordered sequence from TmpA[] to A[] */
void Merge1(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, Tmp;

	LeftEnd = R - 1;	/* The end position of left part */
	Tmp = L;	/* The starting position of ordered sequence */
	while (L <= LeftEnd && R <= RightEnd)
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];	/* Copy elements in left part into TmpA */
		else
			TmpA[Tmp++] = A[R++];	/* Copy elements in right part into TmpA */
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];	/* Copy the leftover of left part */
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];	/* Copy the leftover of right part */
}

/**
 * function: merge the adjacent two subsequences
 * length: equals to the length of the current ordered subsequence 
 */
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{
	int i, j;

	/* When parameter length is an odd number, the last pair may be in 
	 * different size, 'i<=N-2*length' means to merge until we meet the last 
	 * but two subsequence, then merge the tail pair
	 */ 
	for (i = 0; i <= N-2*length; i += 2*length)
		Merge1(A, TmpA, i, i+length, i+2*length-1);

	if (i+length < N)	/* Merge the last 2 sub-sequences */
		Merge1(A, TmpA, i, i+length, N-1);
	else	/* There's only 1 sub-sequence left */
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

/* Unified interface */
void Merge_Sort(ElementType A[], int N)
{ 
	int length; 
	ElementType *TmpA;

	length = 1;		/* Initialize the length of subsequence */
	TmpA = (ElementType *) malloc(N * sizeof(ElementType));

	if (TmpA == NULL)
		printf("No enough space!\n");
	else {
		/* Two steps merge to guarantee the result will be stored in A */
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
}

// Or ...
#define maxn 100000
void merge(int A[], int L1, int R1, int L2, int R2)
{
	int i = L1, j = L2;
	int temp[maxn], index = 0;
	while (i <= R1 && j <= R2)
		if (A[i] <= A[j]) temp[index++] = A[i++];
		else temp[index++] = A[j++];
	while (i <= R1) temp[index++] = A[i++];
	while (j <= R2) temp[index++] = A[j++];
	for (int i = 0; i < index; i++)
		A[L1+i] = temp[i];
}

void mergeSort(int A[], int n)
{
	for (int step = 2; step/2 < n; step *= 2)
		for (int i = 0; i < n; i += step) {
			int mid = i + step/2 - 1;
			if (mid + 1 < n)
				merge(A, i, mid, mid+1, min(i+step-1, n-1));
		}
}

// Favorable
void mergeSort(int A[], int n)
{
	for (int step = 2; step/2 < n; step *= 2) {
		for (int i = 0; i < n; i += step)
			sort(A+i, A+min(i+step, n));
		// Do something
	}
}


