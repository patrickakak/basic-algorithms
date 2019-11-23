/**
 * Find the Kth largest number in an array S[]
 */

void Swap(ElementType *X, ElementType *Y)
{
	ElementType tmp;

	tmp = *X; *X = *Y; *Y = tmp;
}

/* Find Kth in S[Left]~S[Right]: (0 < K <= Right-Left+1), (Left <= Right)
 *
 * Select the first element in S[] as e (benchmark number)
 * Divide elements into two parts: {S1}, {S2} 
 * Set {S1} contains elements greater than or equal to e,
 * Set {S2} contains elements less than e 
 */
ElementType FindKthLargest(ElementType S[], int K, int Left, int Right)
{
	ElementType e = S[Left];
	int L = Left, R = Right;

	while (1) {
		while ((Left <= Right) && (e <= S[Left]))
			Left++;
		/* If Left >= Right, then there's no data left to be processed */
		while ((Left < Right) && (e > S[Right]))
			Right--;
		if (Left < Right)
			Swap(&S[Left], &S[Right]);
		else
			break;
	}
	Swap(&S[Left-1], &S[L]);
	/* LenS1: Number of elements in {S1} equals to Len(S[L]~S[Left-1])-1 */
	if (Left-L-1 >= K)	/* If Length of {S1} >= K */
		return FindKthLargest(S, K, L, Left-2);
	/* Length of {S1} == K-1, which indicate e is the target */
	else if (Left-L-1 == K-1)
		return e;
	else	/* Then it must be inside {S2} */
		return FindKthLargest(S, K-(Left-L-1)-1, Left, R);
}

ElementType Median(ElementType S[], int N)
{
	return FindKthLargest(S, (N+1)/2, 0, N-1);
}

