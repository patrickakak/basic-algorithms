/**
 * Tower Hopper problem
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn];
int main() {
	/*           5           dp[1][1]
	 *          / \            .
	 *         8   3           .
	 *        / \ / \          .
	 *       12  7  16       dp[i][1] ~ dp[i][i]
	 *      /  \/ \ / \        .
	 *     4   10  11  6       .
	 *    /  \ / \/ \ / \      .
	 *   9    5  3   9   4   dp[n][1] ~ dp[n][n]
	 */
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &f[i][j]);
	for (int j = 1; j <= n; j++)
		dp[n][j] = f[n][j];
	for (int i = n-1; i >= 1; i--)
		for (int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
	printf("%d\n", dp[1][1]);
	return 0;
}
