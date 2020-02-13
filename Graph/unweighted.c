/**
 * Unweighted single-source shortest path problem (SSSP)
 * (quite resembles breadth first search algorithm)
 *
 * Psudocode for SSSP problem:
 * Initialize array dist[] and path[] as -1 firstly 
 * */
void Unweighted(Vertex S) {
	Enqueue(S, Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W: each adjacent node of V)
			if (W: has not been visited (i.e. dist[W] == -1)) {
				Update dist[W] into dist[V]+1;
				Update path[W] to V;
				Enqueue(W, Q);
			}
	}
}
/**
 * Adjacency list implementation (T = O(|V|+|E|)):
 */
void Unweighted(LGraph Graph, int dist[], int path[], Vertex S) {
	Queue Q = CreateQueue(Graph->Nv);
	dist[S] = 0;
	Enqueue(Q, S);
	while (!IsEmpty(Q)) {
		Vertex V = Dequeue(Q);
		for (PtrToAdjVNode W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (dist[W->AdjV] == -1) {
				dist[W->AdjV] = dist[V] + 1;
				path[W->AdjV] = V;
				Enqueue(Q, W->AdjV);
			}
	}
}
/**
 * Adjacency matrix implementation (T = O(|V|^2)):
 */
void Unweighted(MGraph Graph, int dist[], int path[], Vertex S) {
	Queue Q = CreateQueue(Graph->Nv);
	dist[S] = 0;
	Enqueue(Q, S);
	while (!IsEmpty(Q)) {
		Vertex V = Dequeue(Q);
		for (Vertex W = 0; W < Graph->Nv; W++)
			if (Graph->G[V][W] < INFINITY && dist[W] == -1) {
				dist[W] = dist[V] + 1;
				path[W] = V;
				Enqueue(Q, W);
			}
	}
}
