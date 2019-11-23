/**
 * Knapsack problem (NP problem)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;
const int maxv = 1000;
int w[maxn], c[maxn], dp[maxv];


int main()
{
	int n, V;

	// 5 8
	// 3 5 1 2 2
	// 4 5 2 1 3
	scanf("%d%d", &n, &V);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int v = 0; v <= V; v++)
		dp[v] = 0;
	
	// dp[v] = max{ dp[v], dp[v-w[i]] + c[i] }
	//          (1<= i <=n, w[i] <= v <= V)
	for (int i = 1; i <= n; i++)
		for (int v = V; v >= w[i]; v--)
			dp[v] = max(dp[v], dp[v-w[i]] + c[i]);
	int max = 0;
	for (int v = 0; v <= V; v++)
		if (dp[v] > max)
			max = dp[v];
	// 10
	printf("%d\n", max);

	return 0;
}


