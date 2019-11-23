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
	int Nv;		/* Number of vertex */
	int Ne;		/* Number of edge   */
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];	/* To store data in vertex */
};
typedef PtrToGNode MGraph;	/* Matrix Graph */

typedef int Vertex;		/* Using the index of vertex to represent a vertex */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;		/* Directed edge <V1, V2> */
	WeightType Weight;	/* Weight */
};
typedef PtrToENode Edge;

/**
 * Functions 
 */
MGraph CreatGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph) malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	/* Notes: the index of vertex from 0 To (Graph->Nv-1) by default */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* Insert an edge <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;

	/* Undirected Graphs, need to insert edge<V2, V1> also */
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);
	Graph = CreatGraph(Nv);
	scanf("%d", &Graph->Ne);
	if (Graph->Ne != 0) {
		E = (Edge) malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
		free(E);
	}
	/* If there's a need to read the data of vertex */
	for (V = 0; V < Graph->Nv; V++)
		scanf(" %c", &Graph->Data[V]);

	return Graph;
}

void DestroyGraph(MGraph Graph)
{
	free(G);
}

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

