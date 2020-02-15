/**
 * Table sort:
 * Worst: Tw = T(algorithm choosed)
 *
 * When elements in A[] is rather large and can not be moved easily, 
 * use indirect sorting (moving pointers instead)
 */
void TableSort(ElementType A[], int N) {
	int P, i, Tmp, *Tbl;
	Tbl = (int *) malloc(N * sizeof(int));
	for (i = 0; i < N; i++)
		Tbl[i] = i;
	for (P = 1; P < N; P++) {
		Tmp = Tbl[P];
		for (i = P; i>=1 && A[i-1].key>A[Tmp].key; i--)
			Tbl[i] = Tbl[i-1];
		Tbl[i] = Tmp;
	}
	free(Tbl);
}
