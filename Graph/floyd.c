/**
 * Adjacency matrix: All pairs shortest path problem (APSP)
 *
 * [Sparse Graph algorithm]:
 * ---- Method 1 (same as V size the single source shortest path problem) ----
 *   One can implement function FindMinDist() by using MinHeap, 
 * Ta=O(|V|^2 * log|V|), Tb=O(|V||E|log|V|), Total T = O(|V|*(|V|+|E|)log|V|) 
 *
 * ------------------------- Method 2  ---------------------------------------
 *   Scan all the uncollected vertices, in this way, 
 * Ta=O(|V|^3), Tb=O(|E||V|), Total T = Ta + Tb = O(|V|^3 + |E||V|)
 *
 * [Dense Graph algorithms] (i.e. E = O(|V|^2)):
 * ------------------------ Method 3 (exactly T=O(|V|^3)) --------------------
 *   Floyd algorithm with elegancy, could handle with negative-weighted edge, 
 * but couldn't tackle negative-cost cycle also.
 *
 * Initiaization: for (each v in G), set D[v][v] = 0, D[i][j] = G[i][j]
 */
bool Floyd(MGraph Graph, WeightType D[][MaxNVertex], Vertex path[][MaxNVertex]) {
	for (Vertex i = 0; i < Graph->Nv; i++)
		for (Vertex j = 0; j < Graph->Nv; j++) {
			D[i][j] = Graph->G[i][j];
			path[i][j] = -1;
		}
	for (Vertex k = 0; k < Graph->Nv; k++)
		for (Vertex i = 0; i < Graph->Nv; i++)
			for (Vertex j = 0; j < Graph->Nv; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					if (i == j && D[i][j] < 0) return false;
					path[i][j] = k;
				}
	return true;
}
