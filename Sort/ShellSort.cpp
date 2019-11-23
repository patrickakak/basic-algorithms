/**
 * Shell sort (unstable):
 *
 * In this case, we use Sedgewick's gap sequence,
 * Worst(unproved): Tw = Θ(N^4/3), extra S = O(1)
 */
void ShellSort(ElementType A[], int N)
{
	int Si, D, P, i;
	ElementType Tmp;
	/* Only a small part of the increments */
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

	/**
	 * The initial increment(i.e. Sedgewick[Si]) can't exceed the length 
	 * of the unsorted sequence 
	 */
	for (Si = 0; Sedgewick[Si] >= N; Si++) ;

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for (P = D; P < N; P++) {	/* Insertion sort */
			Tmp = A[P];
			for (i = P; i >= D && A[i-D] > Tmp; i -= D)
				A[i] = A[i-D];
			A[i] = Tmp;
		}
	/**
	 * Original Shell sort: (increments may be not coprime(e.g. 8-4-2-1)) 
	 * Worst: Tw=Θ(N^2), one can use other different incremental seqeunces to 
	 * solve it (e.g. Hibboard(unproved: Tw=O(N^3/2)) or Sedgewick sequence)
	 */
	/*
	for (D = N/2; D > 0; D /= 2)
		for (P = D; P < N; P++) {
			Tmp = A[P];
			for (i = P; i>=D && A[i-D]>Tmp; i-=D)
				A[i] = A[i-D];
			A[i] = Tmp;
		}
	*/
}

