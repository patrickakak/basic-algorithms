/**
 * Graph adjacency list implementation (suit for sparse graph):
 * Time complexity: T = O(N+E)
 */
typedef int Vertex;
typedef int WeightType;
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};
#define MaxVertexNum 100
typedef char DataType;
typedef struct VNode {
	PtrToAdjVNode FirstEdge;
	DataType Data;
} AdjList[MaxVertexNum];
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv, Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;
LGraph CreatGraph(int VertexNum) {
	LGraph Graph = (LGraph) malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (Vertex V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}
void InsertEdge(LGraph Graph, Edge E) {
	PtrToAdjVNode NewNode = (PtrToAdjVNode) malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	NewNode = (PtrToAdjVNode) malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}
LGraph BuildGraph() {
	int Nv;
	scanf("%d", &Nv);
	LGraph Graph = CreatGraph(Nv);
	scanf("%d", &Graph->Ne);
	if (Graph->Ne) {
		Edge E = (Edge) malloc(sizeof(struct ENode));
		for (int i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
		free(E);
	}
	for (Vertex V = 0; V < Graph->Nv; V++)
		scanf(" %c", &Graph->G[V].Data);
	return Graph;
}
void DestroyGraph(MGraph Graph) {
	free(G);
}
