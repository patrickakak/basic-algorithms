/**
 * To get all permutations of an array of chars of ints
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


/* n as the number of characters in string, thus
 * n=1 means this time, one perticular permutation is done
 *
 * A problem of length n, swap the first and the last char,
 * then it becomes a problem of length n-1, don't forget to
 * swap back later
 */
void permutation(char s[], int n)
{
	int i;

	if (n == 1)
		printf("%s\n", s);
	else
		for (i = 0; i < n; ++i) {
			swap(s[i], s[n-1]);
			permutation(s, n-1);
			swap(s[i], s[n-1]);
		}
}

// Version 2: using hash
#define maxn 100
bool hashTbl[maxn] = {false};
char result[maxn];
void getPermu(int index, int n, char A[])
{
	if (index == n) {
		for (int i = 0; i < n; i++)
			printf("%c", result[i]);
		printf("\n");
		return ;
	}
	for (int i = 0; i < n; i++)
		if (hashTbl[i] == false) {
			result[index] = A[i];
			hashTbl[i] = true;
			getPermu(index+1, n, A);
			hashTbl[i] = false;
		}
}

/* Version3: STL */
void Permu3(char *s, int len)
{
	do {
		for (int i = 0; i < len; i++)
			printf("%c", s[i]);
		printf("\n");
	} while (next_permutation(s, s+len));
}

int main()
{
	char s[100] = "abc";
	int len = strlen(s);

	/* Version1: using swap */
	// permutation(s, len);
	
	/* Version2: using hash */
	// getPermu(0, len, s);

	/* Version3: STL */
	Permu3(s, len);

	return 0;
}

