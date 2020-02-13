/**
 * Graph adjacency matrix implementation:
 * (suit for dense graph and vertices are around 1000 at maximum)
 * Time complexity: T = O(N^2)
 */ 
#define MaxVertexNum 10
#define INFINITY 65535
typedef int WeightType;
typedef char DataType;
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv, Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;
typedef int Vertex;
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;
MGraph CreatGraph(int VertexNum) {
	MGraph Graph = (MGraph) malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (Vertex V = 0; V < Graph->Nv; V++)
		for (Vertex W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	return Graph;
}
void InsertEdge(MGraph Graph, Edge E) {
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}
MGraph BuildGraph() {
	int Nv;
	scanf("%d", &Nv);
	MGraph Graph = CreatGraph(Nv);
	scanf("%d", &Graph->Ne);
	if (Graph->Ne != 0) {
		Edge E = (Edge) malloc(sizeof(struct ENode));
		for (int i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
		free(E);
	}
	for (Vertex V = 0; V < Graph->Nv; V++)
		scanf(" %c", &Graph->Data[V]);
	return Graph;
}
void DestroyGraph(MGraph Graph) {
	free(G);
}
// can also work
/*
// Less troublesome way while you're in a test or something
int G[MAXN][MAXN], Nv, Ne;	// Global variables
void BuildGraph()
{
	int i, j, v1, v2, w;

	scanf("%d", &Nv);
	// CreatGraph
	for (i = 0; i < Nv; i++)
		for (j = 0; j < Nv; j++)
			G[i][j] = INFINITY;
	scanf("%d", &Ne);
	for (i = 0; i < Ne; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		// InsertEdge
		G[v1][v2] = w;
		G[v2][v1] = w;
	}
}
*/
