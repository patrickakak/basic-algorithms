int Max3(int A, int B, int C) {
    return A > B ? A > C ? A : C : B > C ? B : C;
}
int DivideAndConquer(int A[], int left, int right) {
	if (left == right) {
		if (A[left] > 0) return A[left];
		else return 0;
	}
	int centre = (left + right) / 2;
	int MaxLeftSum = DivideAndConquer(A, left, centre);
	int MaxRightSum = DivideAndConquer(A, centre + 1, right);
	int MaxLeftBorderSum = 0, LeftBorderSum = 0;
	for (int i = centre; i >= left; i--) {
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum) MaxLeftBorderSum = LeftBorderSum;
	}
	MaxRightBorderSum = 0, RightBorderSum = 0;
	for (int i = centre + 1; i <= right; i++) {
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum) MaxRightBorderSum = RightBorderSum;
	}
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int MaxSubseqSum3(int A[], int N) {
	return DivideAndConquer(A, 0, N - 1);
}
int MaxSubseqSum4(int A[], int N) {
	int MaxSum = 0, ThisSum = 0;
	for (int i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) MaxSum = ThisSum;
		else if (ThisSum < 0) ThisSum = 0;
	}
	return MaxSum;
}
