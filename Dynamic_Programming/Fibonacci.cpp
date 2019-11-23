/**
 * Dynamic Programming:
 * (to solve overlapping subproblems...)
 */
#include <cstdio>
#include <cstring>

#define Max_N 1010

int fib(int n)
{
	if (n == 0 || n == 1) return 1;
	if (dp[n] != -1) return dp[n];
	else {
		dp[n] = fib(n-1) + fib(n-2);
		return dp[n];
	}
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int dp[Max_N];

	memset(dp, -1, sizeof(dp));
	printf("%d\n", fib(105));

	return 0;
}


