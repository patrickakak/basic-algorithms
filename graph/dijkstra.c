/**
 * Weighted single source shortest path problem: 
 * (with adjacency matrix in a connected or unconncected graph)
 *
 * Psudocode for dijkstra's algorithm: (could not tackle the problem with 
 * negative-weighted edge and negative-cost cycle)
 */
void Dijkstra(Vertex s) {
	while (1) {
		V = vertex with the minimum distance among those uncollected vertices;
		if (No such V) break;
		colloected[V] = true;
		for (W: each node next to V)
			if (collected[W] == false)
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
Vertex FindMinDist(MGraph Graph, int dist[], bool collected[]) {
	Vertex MinV;
	int MinDist = INFINITY;
	for (Vertex V = 0; V < Graph->Nv; V++)
		if (collected[V] == false && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	if (MinDist < INFINITY) return MinV;
	else return ERROR;
}
/**
 * Dijkstra's algorithm solves the single-source shortest path problem 
 * with non-negative edge weight. 
 */
bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S) {
	bool collected[MaxVertexNum];
	for (Vertex V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY) path[V] = S;
		else path[V] = -1;
		collected[V] = false;
	}
	dist[S] = 0;
	collected[S] = true;
	while (1) {
		Vertex V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) break;
		collected[V] = true;
		for (Vertex W = 0; W < Graph->Nv; W++)
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0) return false;
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W];
					path[W] = V;
				}
			}
	}
	return true;
}
