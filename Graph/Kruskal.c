/**
 * Adjacency list implementaton: T = O(|E|log|E|)
 *   Kruskal to generate minimum spinning tree (suit for sparse graph )
 */

/*---------- Union-Find (or disjoint-set data structure) definition --------*/
typedef Vertex ElementType;
typedef Vertex SetName;		/* Set index of root node as the name of a set */
typedef ElementType SetType[MaxVertexNum];	/* Indices begin with 0 */

/* Initialize vertices Set */
void InitializeVSet(SetType S, int N)
{
	ElementType X;

	for (X = 0; X < N; X++) S[X] = -1;
}

/* Roo1 and Root2 represent different root node of different sets by default */
void Union(SetType S, SetName Root1, SetName Root2)
{
	/* Small Set merged into a bigger one */
	if (S[Root2] < S[Root1]) {	/* If Set2 is larger */
		S[Root2] += S[Root1];	/* Merge Set1 into Set2 */
		S[Root1] = Root2;
	} else {
		S[Root1] += S[Root2];	/* Merge Set2 into Set1 */
		S[Root2] = Root1;
	}
}

/* Initialize elements in Set as -1 */
SetName Find(SetType S, ElementType X)
{
	if (S[X] < 0)	/* Find the root of Set */
		return X;
	else	/* Path compression technique */
		return S[X] = Find(S, S[X]);
}

/* To check the edge <V1, V2> can form a cycle in current MST */
bool CheckCycle(SetType VSet, Vertex V1, Vertex V2)
{
	Vertex Root1, Root2;

	Root1 = Find(VSet, V1);		/* Get the root of set of V1 */
	Root2 = Find(VSet, V2);		/* Get the root of set of V2 */

	/* If V1 and V2 are already in same Set, discard E<v1, v2> */
	if (Root1 == Root2)
		return false;
	else {	/* Ddge is collectable, merge the sets of V1 and V2 */
		Union(VSet, Root1, Root2);
		return true;
	}
}
/*-------------------- End of Union-Find definition --------------------*/

/*-------------------- MinHeap of edges definition --------------------*/
/* Re-organize edge array to be a MinHeap of Weight based on ESet[p] as root */
void PercDown(Edge ESet, int p, int N)
{
	int Parent, Child;
	struct ENode X;

	X = ESet[p];	/* Get the value stored in root */
	for (Parent = p; (Parent*2+1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N-1) && (ESet[Child].Weight > ESet[Child+1].Weight))
			Child++;	/* Child to point to the smaller one */
		if (X.Weight <= ESet[Child].Weight)
			break;	/* Find the right place */
		else	/* Percolate X down */
			ESet[Parent] = ESet[Child];
	}
	ESet[Parent] = X;
}

/* Recruit edges into ESet array and initialize it as MinHeap */
void InitializeESet(LGraph Graph, Edge ESet)
{
	Vertex V;
	PtrToAdjVNode W;
	int ECount;

	/* Recruit edges into ESet */
	ECount = 0;
	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			/* To avoid recruiting repeatedly, recruit edge with V1<V2 only */
			if (V < W->AdjV) {
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W->AdjV;
				ESet[ECount++].Weight = W->Weight;
			}
	/* Initialize it as Min-heap */
	for (ECount = Graph->Ne/2; ECount >= 0; ECount--)
		PercDown(ESet, ECount, Graph->Ne);
}

/* Given current size of Min-heap, get the edge with smallest 
 * weight and rearrange the Min-heap */
int GetEdge(Edge ESet, int CurrentSize)
{
	Swap(&ESet[0], &ESet[CurrentSize-1]);
	PercDown(ESet, 0, CurrentSize-1);

	return CurrentSize-1;	/* Return the position of minimum edge in ESet */
}
/*-------------------- MinHeap of edges definition --------------------*/

/* Generate MST as a graph implemented by adjacency list and return 
 * the total weight */
int Kruskal(LGraph Graph, LGraph MST)
{
	WeightType TotalWeight;
	int ECount, NextEdge;
	SetType VSet;	/* Vertices array */
	Edge ESet;	/* Edges array */

	InitializeVSet(VSet, Graph->Nv);	/* Initialize vertices set */
	ESet = (Edge) malloc(sizeof(struct ENode) * Graph->Ne);
	InitializeESet(Graph, ESet);	/* Initialize the Min-heap of edges */

	/* Creata a graph with all vertices but no edges (by using 
	 * adjacency list to generate MST) */
	MST = CreateGraph(Graph->Nv);
	TotalWeight = 0;
	ECount = 0;

	NextEdge = Graph->Ne;	/* The original scale of ESet */
	/* When edges collected are not enough to form a tree */
	while (ECount < Graph->Nv-1) {
		/* To get the position of minimum edge from ESet */
		NextEdge = GetEdge(ESet, NextEdge);
		if (NextEdge < 0)
			break;	/* Empty edge set */
		/**
		 * If no cycle is formed when this edge is added 
		 * (i.e. they don't belong to the same Set) 
		 */
		if (CheckCycle(VSet, ESet[NextEdge].V1, ESet[NextEdge].V2) == true) {
			InsertEdge(MST, ESet+NextEdge);		/* Insert such edge into MST */
			TotalWeight += ESet[NextEdge].Weight;	/* Total weight */
			ECount++;	/* Edge counter */
		}
	}
	if (ECount < Graph->Nv-1)
		TotalWeight = -1;	/* Error mark to indicate no such spinning tree */
	return TotalWeight;
}

