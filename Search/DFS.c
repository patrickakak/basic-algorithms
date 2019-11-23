/**
 * Depth First Search (pseudocode): 
 *   Adjacency list: T = O(N+E), Adjacency matrix: T = O(N^2)
 *   (N/E is the number of vertex/edge respectively)
 */
void DFS(Vertex V)
{
	visited[V] = true;

	for (W: every nearby node of V)
		if (!visited[W])
			DFS(W);
}

void Visit(Vertex V)
{
	printf("Visiting vertex#%d\n", V);
}

/**
 * Graph adjacency matrix implementation (directed graph): 
 * T = O(N^2), traverse every node and its neighbor 
 */

/* visited[] is a global array, initialized to be false */
void DFS_m(MGraph Graph, Vertex V, void (*Visit)(Vertex))
{
	Vertex W;

	Visit(V);
	visited[V] = true;

	for (W = 0; W < Graph->Nv; W++)
		if (!visited[W] && Graph->G[V][W] != INFINITY)
			DFS_m(Graph, W, Visit);
}

/**
 * Graph adjacency list implementation (directed graph): 
 * T = O(N+E), traverse every vertex and edge 
 */

void DFS_l(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{
	PtrToAdjVNode W;

	Visit(V);	/* Visit vertex V */
	visited[V] = true;
	
	for (W = Graph->G[V].FirstEdge; W; W = W->Next)
		if (!Visited[W->AdjV])
			DFS_l(Graph, W->AdjV, Visit);		/* Visit it recursively */
}


/* List all components in a graph wheather it's strongly connected or not */
void ListComponents(Graph G)
{
	for (each V in G)
		if (!visited[V])
			DFS(V); 	/* or BFS(V) */
}

