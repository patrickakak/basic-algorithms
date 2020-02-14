/**
 * Adjacency list implementation: T = O(N+E)
 * TopSort algorithm for AOV(i.e. Activity On Vertex) of directed graph.
 * (could be used to dectect DAG(i.e. directed acyclic graph))
 */
/* TopSort graph, indexes of vertices will be stored into TopOrader[] array 
 * (Note: Prepare a rather large queue space, it can get tricky)
 */
bool TopSort(LGraph Graph, Vertex TopOrder[]) {
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = CreateQueue(MaxVertexNum);
	for (V = 0; V < Graph->Nv; V++)
		Indegree[V] = 0;
	for (V = 0; V < Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++;
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
			Enqueue(Q, V);
	cnt = 0;
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		TopOrder[cnt++] = V;
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)
				Enqueue(Q, W->AdjV);
	}
	if (cnt != Graph->Nv) return false;
	else return true;
}
