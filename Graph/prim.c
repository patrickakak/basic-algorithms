/**
 * Adjacency matrix implementation: 
 *   Prim minimum spanning tree algorithm 
 * (suit for dense graph, headless search: T=O(|V|^2)) 
 */
Vertex FindMinDist(MGraph Graph, WeightType dist[]) {
	Vertex MinV;
	WeightType MinDist = INFINITY;
	for (Vertex V = 0; V < Graph->Nv; V++)
		if (dist[V] != 0 && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	if (MinDist < INFINITY) return MinV;
	else return ERROR;
}
/**
 * To Generate MST(i.e. minimum-spanning-tree) as Graph implemented 
 * in adjacency list and return the total weight 
 */
int Prim(MGraph Graph, LGraph MST) {
	WeightType dist[MaxVertexNum];
	Vertex parent[MaxVertexNum];
	for (Vertex V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[0][V];
		parent[V] = 0;
	}
	WeightType TotalWeight = 0;
	int VCount = 0;
	MST = CreateGraph(Graph->Nv);
	Edge E = (Edge) malloc(sizeof(struct ENode));
	dist[0] = 0;
	VCount++;
	parent[0] = -1;
	while (1) {
		Vertex V = FindMinDist(Graph, dist);
		if (V == ERROR) break;
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;
		for (Vertex W = 0; W < Graph->Nv; W++)
			if (dist[W]!=0 && Graph->G[V][W]<INFINITY)
				if (dist[W] > Graph->G[V][W]) {
					dist[W] = Graph->G[V][W];
					parent[W] = V;
				}
	}
	if (VCount < Graph->Nv) TotalWeight = ERROR;
	return TotalWeight;
}
