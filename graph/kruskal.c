/**
 * Adjacency list implementaton: T = O(|E|log|E|)
 *   Kruskal to generate minimum spinning tree (suit for sparse graph )
 */
/*---------- Union-Find (or disjoint-set data structure) definition --------*/
typedef Vertex ElementType;
typedef Vertex SetName;
typedef ElementType SetType[MaxVertexNum];
void InitializeVSet(SetType S, int N) {
	ElementType X;
	for (X = 0; X < N; X++) S[X] = -1;
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
bool CheckCycle(SetType VSet, Vertex V1, Vertex V2) {
	Vertex Root1 = Find(VSet, V1);
	Vertex Root2 = Find(VSet, V2);
	if (Root1 == Root2) return false;
	else {
		Union(VSet, Root1, Root2);
		return true;
	}
}
/*-------------------- End of Union-Find definition --------------------*/

/*-------------------- MinHeap of edges definition --------------------*/
/* Re-organize edge array to be a MinHeap of Weight based on ESet[p] as root */
void PercDown(Edge ESet, int p, int N) {
	int Parent, Child;
	struct ENode X;
	X = ESet[p];	/* Get the value stored in root */
	for (Parent = p; (Parent*2+1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N-1) && (ESet[Child].Weight > ESet[Child+1].Weight)) Child++;
		if (X.Weight <= ESet[Child].Weight) break;
		else ESet[Parent] = ESet[Child];
	}
	ESet[Parent] = X;
}
void InitializeESet(LGraph Graph, Edge ESet) {
	int ECount = 0;
	for (Vertex V = 0; V < Graph->Nv; V++)
		for (PtrToAdjVNode W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (V < W->AdjV) {
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W->AdjV;
				ESet[ECount++].Weight = W->Weight;
			}
	for (ECount = Graph->Ne/2; ECount >= 0; ECount--)
		PercDown(ESet, ECount, Graph->Ne);
}
/* Given current size of Min-heap, get the edge with smallest 
 * weight and rearrange the Min-heap */
int GetEdge(Edge ESet, int CurrentSize) {
	Swap(&ESet[0], &ESet[CurrentSize-1]);
	PercDown(ESet, 0, CurrentSize-1);
	return CurrentSize - 1;
}
/*-------------------- MinHeap of edges definition --------------------*/

/* Generate MST as a graph implemented by adjacency list and return 
 * the total weight */
int Kruskal(LGraph Graph, LGraph MST) {
	SetType VSet;
	InitializeVSet(VSet, Graph->Nv);
	Edge ESet = (Edge) malloc(sizeof(struct ENode) * Graph->Ne);
	InitializeESet(Graph, ESet);
	MST = CreateGraph(Graph->Nv);
	WeightType TotalWeight = 0;
	int ECount = 0;
	int NextEdge = Graph->Ne;
	while (ECount < Graph->Nv-1) {
		NextEdge = GetEdge(ESet, NextEdge);
		if (NextEdge < 0) break;
		if (CheckCycle(VSet, ESet[NextEdge].V1, ESet[NextEdge].V2) == true) {
			InsertEdge(MST, ESet+NextEdge);
			TotalWeight += ESet[NextEdge].Weight;
			ECount++;
		}
	}
	if (ECount < Graph->Nv-1) TotalWeight = -1;
	return TotalWeight;
}
