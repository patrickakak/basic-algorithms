/**
 * Weighted single source shortest path problem: 
 * (with adjacency matrix in a connected or unconncected graph)
 *
 * Psudocode for dijkstra's algorithm: (could not tackle the problem with 
 * negative-weighted edge and negative-cost cycle)
 */
void Dijkstra(Vertex s)
{
	while (1) {
		/* Time complexity Ta: One can use MinHeap for sparse graph */
		V = vertex with the minimum distance among those uncollected vertices;
		if (No such V)
			break;
		colloected[V] = true;
		for (W: each node next to V)
			if (collected[W] == false)
				/* Time complexity Tb: visit all the edges inside graph:
				 * (when using MinHeap, don't forget to insert the updated 
				 * dist[W] back into heap) */
				if (dist[V]+E<v, w> < dist[W]) {
					dist[W] = dist[V] + E<v, w>;
					path[W] = V;
				}
	}
}

/**
 * Return the minimum element of array dist (among uncollected vertices)
 *
 * Critical implementatons:
 *     a. To get minimum dist value among the uncollected 
 *     b. Update dist[w] (w is an adjacent vertex infected by v)
 * ----------------------- Method 1 ------------------------------------------
 *   Scan all the uncollected vertices, in this case, Ta=O(|V|^2), Tb=O(|E|), 
 *   suit for dense graph (i.e. E = O(|V|^2)). Total T = O(|V|^2 + |E|)
 *
 * ----------------------- Method 2 ------------------------------------------
 *   Also, one can implement function FindMinDist() by using minheap,
 *   Ta=O(|V|log|V|), Tb=O(|E|log|V|), suit for sparse graph, 
 *   Total T = O((|V|+|E|)log|V|)
 */
Vertex FindMinDist(MGraph Graph, int dist[], bool collected[])
{
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++)
		/* If V has not been colloected and dist[V] is smaller */
		if (collected[V] == false && dist[V] < MinDist) {
			MinDist = dist[V];	/* Update minimum distance */
			MinV = V;	/* Update corresponding vertex */
		}
	if (MinDist < INFINITY)		/* Find the minimum dist */
		return MinV;	/* Return the index of the vertex */
	else return ERROR;	/* If no such vertex, return ERROR */
}

/**
 * Dijkstra's algorithm solves the single-source shortest path problem 
 * with non-negative edge weight. 
 */
bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	bool collected[MaxVertexNum];
	Vertex V, W;

	/* Initialization: assume that inexistent edges are represented as 
	 * INFINITY in adjacency matrix
	 *
	 * When using min-heap and insert source vertex into it first, then we
	 * should initialize dist[] as INFINITY, otherwise 
	 * "dist[W] > dist[V]+weight<v,w>" will be skipped.
	 */
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	dist[S] = 0;
	collected[S] = true; 	/* Collect source vertex firstly */
	while (1) {
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) 	/* No such V, end algorithm */
			break;
		collected[V] = true;	/* To collect V */

		/* If W is a vertex next to V and uncollected, check if there's a 
		 * negative weighted edge, if so, return error, otherwise to check 
		 * if there's a need to store new path.
		 */
		for (W = 0; W < Graph->Nv; W++)
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0)
					return false;	/* Can't handle it properly */
				/* If colloecting V can decrease dist[W] */
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W];
					path[W] = V;	/* Update path of S to W */
				}
			}
	}
	return true;	/* End of algorithm, data handled properly */
}

