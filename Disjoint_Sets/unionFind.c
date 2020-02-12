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
void Union(SetType S, SetName Root1, SetName Root2) {
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	} else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}
SetName Find(SetType S, ElementType X) {
	if (S[X] < 0) return X;
	else return S[X] = Find(S, S[X]);
}
