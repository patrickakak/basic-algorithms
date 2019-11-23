/**
 * Find the majority number in an array
 */
#include <cstdio>

const int maxn = 10010;
int A[maxn], n;

// return the index of the majority number
int majority(int A[], int n)
{
	int count = 1, index = 0;
	for (int i = 1; i < n; i++)
		if (A[i] == A[index])
			count++;
		else {
			if (count > 0)
				count--;
			else {
				index = i;
				count = 1;
			}
		}
	int M = 0;
	if (count > 0)
		for (int i = 0; i < n; i++)
			if (A[index] == A[i])
				M++;
	if (M > n/2) return index;
	else return -1;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	// 8
	// 0 5 5 3 5 1 5 7
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int pos = majority(A, n);
	if (pos != -1) printf("m = %d\n", A[pos]);
	else printf("-1\n");

	return 0;
}

