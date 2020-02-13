/**
 * To get a random number
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int A[maxn], n;
int randPartition(int A[], int L, int R) {
	int p = (round(1.0*rand()/RAND_MAX*(R-L) + L));
	swap(A[p], A[L]);
	int tmp = A[L];
	while (L < R) {
		while (L < R && A[R] > tmp) R--;
		A[L] = A[R];
		while (L < R && A[L] <= tmp) L++;
		A[R] = A[L];
	}
	A[L] = tmp;
	return L;
}
int randSelect(int A[], int L, int R, int Kth) {
	if (L == R) return A[L];
	int p = randPartition(A, L, R);
	int M = p - L + 1;
	if (Kth == M) return A[p];
	else if (Kth < M) return randSelect(A, L, p-1, Kth);
	else return randSelect(A, p+1, R, Kth-M);
}
int main() {
	srand((unsigned) time(NULL));
	int sum = 0, sum1 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &A[i]);
		sum += A[i];
	}
	randSelect(A, 0, n-1, n/2);
	for (int i = 0; i < n/2; i++) sum1 += A[i];
	printf("%d\n", (sum-sum1)-sum1);
	return 0;
}
