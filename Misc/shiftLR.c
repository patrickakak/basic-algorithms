/*
 **************************************************
 * Left or Right Shift in a confined array space.
 **************************************************
 */
/**
 * Chirality:
 *
 * Elements in the same part, they go through twice mirror change, so
 * their relative position is unchanged. However, if you see the two
 * parts as two huge elements, both of them have only mirrored once, so
 * the order of those two is reversed for sure.
 */
void Swap(ElementType *X, ElementType *Y) {
	ElementType tmp;
	tmp = *X; *X = *Y; *Y = tmp;
}
void Mirror(ElementType S[], int L, int R) {
	for (int i=L, j=R; i < j; i++, j--)
		Swap(&S[i], &S[j]);
}
/* M: offset (M<N)
 * Divide N elements into two parts: 0~M-1 and M~N-1
 */
void LeftShift(ElementType S[], int N, int M) {
	if (M >= N) return;
	Mirror(S, 0, M-1);
	Mirror(S, M, N-1);
	Mirror(S, 0, N-1);
}
/* M: offset (M<N)
 * Divide N elements into two parts: 0~N-M-1 and N-M~N-1.
 */
void RightShift(ElementType S[], int N, int M) {
	if (M >= N) return;
	LeftShift(S, N, N-M);
}
