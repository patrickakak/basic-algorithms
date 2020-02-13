/**
 * Longest Increasing Sequence, can be discontinuous
 * (T = O(N^2) by using dynamic programming)
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;
// dp[i] is the LIS with the i-th element as the end
int A[N], dp[N];
int main() {
	// 8
	// 1 2 3 -9 3 9 0 11
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	// dp[i] = max{1, dp[j]+1}
	// (j = 1, 2, ..., i-1 && A[j] < A[i])
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if (A[i] >= A[j] && (dp[j]+1 > dp[i]))
				dp[i] = dp[j] + 1;
		ans = max(ans, dp[i]);
	}
	// {1, 2, 3, 3, 9, 11}
	printf("%d\n", ans);
	return 0;
}
