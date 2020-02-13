#include <iostream>
#include <vector>
using namespace std;
vector<int> dp(1010, -1);
int fib(int n) {
	if (n == 0 || n == 1) return 1;
	if (dp[n] != -1) return dp[n];
	else {
		dp[n] = fib(n-1) + fib(n-2);
		return dp[n];
	}
}
int main() {
	printf("%d\n", fib(105));
	return 0;
}
