/**
 * Maximum Subsequence Sum in four ways
 */
#include <stdio.h>

#define MAXK 10

static int DivideAndConquer(int A[], int left, int right);
static int Max3(int A, int B, int C);

int MaxSubseqSum1(int A[], int N);	/* MaxSubseqSum1: T=O(N^3) */
int MaxSubseqSum2(int A[], int N);	/* MaxSubseqSum2: T=O(N^2) */
int MaxSubseqSum3(int A[], int N);	/* MaxSubseqSum2: T=O(NlogN) */
int MaxSubseqSum4(int A[], int N);	/* MaxSubseqSum2: T=O(N) */

int main(void)
{
	int array[MAXK] = {-3, 4, 4, -8, 1, 0, 6, -2, 1, 0};

	printf("Maximum subsequence sum: %d\n", MaxSubseqSum3(array, MAXK));

	return 0;
}

/* MaxSubseqSum1: T(N^3) */
int MaxSubseqSum1(int A[], int N)
{
	int ThisSum, MaxSum;
	int i, j, k;

	MaxSum = 0;
	for (i = 0; i < N; i++)
		for (j = i; j < N; j++) {
			ThisSum = 0;
			for (k = i; k <= j; k++) {
				ThisSum += A[k];
				if (ThisSum > MaxSum)
					MaxSum = ThisSum;
			}
		}

	return MaxSum;
 }

/* MaxSubseqSum2: T(N^2) */
int MaxSubseqSum2(int A[], int N)
{
	int ThisSum, MaxSum;
	int i, j;

	MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum = 0;
		for (j = i; j < N; j++) {
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

/* MaxSubseqSum3: T(NlogN) */
int MaxSubseqSum3(int A[], int N)
{
	return DivideAndConquer(A, 0, N-1);
}

/* MaxSubseqSum4: T(N) */
int MaxSubseqSum4(int A[], int N)
{
	int ThisSum, MaxSum;
	int i;

	MaxSum = 0;
	ThisSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) MaxSum = ThisSum;
		if (ThisSum < 0) ThisSum = 0;
	}
	return MaxSum;
}

static int DivideAndConquer(int A[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;	/* The result of left and right part respectively */
	int MaxLeftBorderSum, MaxRightBorderSum;	/* To store the result acrossing the border */
	int LeftBorderSum, RightBorderSum;
	int centre, i;

	if (left == right) {	/* Condition to quit */
		if (A[left] > 0) return A[left];
		else return 0;
	}
	/* Divide procedure */
	centre = (left + right) / 2;	/* To find the centre */
	/* To get maximum of each part recursively */
	MaxLeftSum = DivideAndConquer(A, left, centre);
	MaxRightSum = DivideAndConquer(A, centre+1, right);

	/* To get maximum of the number acrossing the border */
	MaxLeftBorderSum = 0, LeftBorderSum = 0;
	for (i = centre; i >= left; i--) {	/* Scan from centre to left */
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	} /* Left part done */

	MaxRightBorderSum = 0, RightBorderSum = 0;
	for (i = centre+1; i <= right; i++) {	/* Scan from centre to right */
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	} /* Right part done */

	/* Return the maximum of the three */
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum+MaxRightBorderSum);
}

static int Max3(int A, int B, int C)
{
	return A > B ? A > C ? A : C : B > C ? B : C;
}

