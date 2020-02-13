/**
 * Longest Common Subsequence, can be discontinuous
 * T = O(nm) by using dynamic programming
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100;
char A[N], B[N];
int dp[N][N];
int main() {
	// sadstory
	// adminsorry
	gets(A+1);
	gets(B+1);
	int lenA = strlen(A+1);
	int lenB = strlen(B+1);
	for (int i = 0; i <= lenA; i++) dp[i][0] = 0;
	for (int j = 0; j <= lenB; j++) dp[0][j] = 0;
	//             / dp[i][j-1]+1, A[i]==B[j]
	// dp[i][j] = 
	//             \ max{ dp[i-1][j], dp[i][j-1], A[i]!=B[j] }
	for (int i = 0; i <= lenA; i++)
		for (int j = 1; j <= lenB; j++)
			if (A[i] == B[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	// 6
	printf("%d\n", dp[lenA][lenB]);
	return 0;
}
