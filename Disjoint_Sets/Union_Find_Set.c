/**
 * IMPLIMENTATION OF Union-Find-Set
 */
#define MAXN 1000
typedef int ElementType;	/* Elements are non-negative integers */
typedef int SetName;		/* Use index of root as the name of Set */
typedef ElementType SetType[MAXN];

void Init(SetType S, int N)
{
	int i;
	for (i = 0; i < N; i++)
		S[i] = -1;
}

/* Prerequisite: Root1 and Root2 are root of different set */
void Union(SetType S, SetName Root1, SetName Root2)
{
	/* Merge the smaller one into the larger one */
	if (S[Root2] < S[Root1]) {		/* Set2 is larger */
		S[Root2] += S[Root1];		/* Merge into Set2 */
		S[Root1] = Root2;
	} else {						/* Set1 is larger */
		S[Root1] += S[Root2];		/* Merge */
		S[Root2] = Root1;
	}
}

/* Find the 1st ancestor of element X: index of root */
SetName Find(SetType S, ElementType X)
{
	if (S[X] < 0) return X; 		/* Find the root of Set */
	else return S[X] = Find(S, S[X]); 	/* Path compression */
}


