/**
 * Depth First Search (pseudocode): 
 *   Adjacency list: T = O(N+E), Adjacency matrix: T = O(N^2)
 *   (N/E is the number of vertex/edge respectively)
 */
void DFS(Vertex V) {
	visited[V] = true;
	for (W: every nearby node of V)
		if (!visited[W]) DFS(W);
}

/**
 * Graph adjacency matrix implementation (directed graph): 
 * T = O(N^2), traverse every node and its neighbor 
 */
void DFS_m(MGraph Graph, Vertex V, void (*Visit)(Vertex)) {
	Visit(V);
	visited[V] = true;
	for (Vertex W = 0; W < Graph->Nv; W++)
		if (!visited[W] && Graph->G[V][W] != INFINITY)
			DFS_m(Graph, W, Visit);
}

/**
 * Graph adjacency list implementation (directed graph): 
 * T = O(N+E), traverse every vertex and edge 
 */
void DFS_l(LGraph Graph, Vertex V, void (*Visit)(Vertex)) {
	Visit(V);
	visited[V] = true;
	for (PtrToAdjVNode W = Graph->G[V].FirstEdge; W; W = W->Next)
		if (!Visited[W->AdjV])
			DFS_l(Graph, W->AdjV, Visit);
}
void ListComponents(Graph G) {
	for (each V in G)
		if (!visited[V]) DFS(V);
}
