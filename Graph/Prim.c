/**
 * Adjacency matrix implementation: 
 *   Prim minimum spanning tree algorithm 
 * (suit for dense graph, headless search: T=O(|V|^2)) 
 */

/* Return the vertex of minimum dist[v] among those uncollected vertices */
Vertex FindMinDist(MGraph Graph, WeightType dist[])
{
	Vertex MinV, V;
	WeightType MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; V++)
		/* If uncollected[V] and it has the minimum dist */
		if (dist[V] != 0 && dist[V] < MinDist) {
			MinDist = dist[V];	/* Update minimum distance */
			MinV = V;	/* Update vertex */
		}
	if (MinDist < INFINITY)
		return MinV;
	else return ERROR;	/* If no such vertex, return -1 as a remark */
}

/**
 * To Generate MST(i.e. minimum-spanning-tree) as Graph implemented 
 * in adjacency list and return the total weight 
 */
int Prim(MGraph Graph, LGraph MST)
{
	WeightType dist[MaxVertexNum], TotalWeight;
	Vertex parent[MaxVertexNum], V, W;
	int VCount;
	Edge E;

	/* Initialization: set source vertex as v0 by default */
	for (V = 0; V < Graph->Nv; V++) {
		/* Assume that when initializing Graph, if there's no direct path 
		 * from vertex V to W, then define Graph->G[V][W] as INFINITY */
		dist[V] = Graph->G[0][V];
		parent[V] = 0;	/* Set the parents of all vertices as 0 */
	}
	TotalWeight = 0;
	VCount = 0;		/* Vertices counter */
	/* Create a graph with all vertices but no edge (by using adjacency 
	 * list graph as an entity of MST) */
	MST = CreateGraph(Graph->Nv);
	E = (Edge) malloc(sizeof(struct ENode));

	dist[0] = 0;	/* Recruit source vertex into MST */
	VCount++;
	parent[0] = -1;		/* To indicate v0 is root node */

	while (1) {
		/* V with the minimum dist[V] among uncollected vertices */
		V = FindMinDist(Graph, dist);
		if (V == ERROR)
			break;	/* V doesn't exist */
		/**
		 * Recruit V and insert E<parent[V], V> into MST, (Don't bother to 
		 * consider whether there's a cycle formed when inserting an edge) 
		 */
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;

		for (W = 0; W < Graph->Nv; W++)
			/* If W is uncollected and also next to V */
			if (dist[W]!=0 && Graph->G[V][W]<INFINITY)
				/* If the recruitment of V can decrease dist[W], update 
				 * dist[W] and parent node of W for later weight calculation */
				if (dist[W] > Graph->G[V][W]) {
					dist[W] = Graph->G[V][W];
					parent[W] = V;
				}
	}
	if (VCount < Graph->Nv)		/* Vertices in MST is less than V */
		TotalWeight = ERROR;
	/* End of Prim, return minimum total wieght or error */
	return TotalWeight;
}

