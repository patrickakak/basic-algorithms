/**
 * IMPLIMENTATION OF Union-Find-Set
 */
#define MAXN 1000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];
void Init(SetType S, int N) {
	for (int i = 0; i < N; i++)
		S[i] = -1;
}
/* Merge trees according to rank, in worst case, the height of tree will be
 * H = O(logN) */
void Union(SetType S, SetName Root1, SetName Root2) {
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	} else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}
/* Path compression (refer to Ackermann Function)
 * 
 * k1Ma(M, N) <= T(M, N) <= k2Ma(M, N)
 *
 *            /  2^j                (i=1 and j>=1)
 * A(i, j) =     A(i-1, 2)          (i>=2 and j=1)
 *            \  A(i-1, A(i, j-1))  (i>=2 and j>=2)
 *
 * a(M, N) = min{ i>=1 | A(i, [M/N]) > logN } <= O(log*N) <= 4 (normally) 
 */
SetName Find(SetType S, ElementType X) {
	if (S[X] < 0) return X;
	else return S[X] = Find(S, S[X]);
}
