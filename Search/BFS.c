/**
 * Breadth First Search (pseudocode): 
 *   Adjacency list: T = O(N+E), Adjacency matrix: T = O(N^2) 
 *   (N/E is the number of vertex/edge respectively)
 */
void BFS(Vertex V)
{
	visited[V] = true;

	Enqueue(V, Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W: every node next to V)
			if (!visited[W]) {
				visited[W] = true;
				Enqueue(W, Q);
			}
	}
}

/**
 * Graph adjacency matrix implementation (directed graph): 
 * T = O(N^2): Same as DFS_m
 */

/* IsEdge() to check whether edge<V, W> is one of the edges of Graph or not. 
 * In this case, a inexistent edge is marked as INFINITY when initialized: */
bool IsEdge(Mgraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}

/* visited[] is a global array, initialized to be false */
void BFS_m(MGraph Graph, Vertex S, void (*Visit)(Vertex))
{
	Queue Q;
	Vertex V, W;

	Q = CreatQueue(MaxSize);	/* Create a empty queue with size of MaxSize */
	Visit(S);	/* Do something with vertex S */
	visited[S] = true;
	Enqueue(Q, S);

	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W = 0; W < Graph->Nv; W++)
			/* If W is the adjacent node of V and never visited before: */
			if (!visited[W] && IsEdge(Graph, V, W)) {
				Visit(W);
				visited[W] = true;
				Enqueue(Q, W);
			}
	}
	DestroyQueue(Q);
}

/**
 * Graph adjacency list implememtation (directed graph): 
 * T = O(N+E): Same as DBS_l
 */

void BFS_l(LGraph Graph, Vertex S, void (*Visit)(Vertex))
{
	Queue Q;
	Vertex V;
	PtrToAdjVNode W;

	Q = CreatQueue(MaxSize);
	Visit(S);
	visited[S] = true;
	Enqueue(Q, S);

	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (!visited[W->AdjV]) {
				Visit(W->AdjV);
				visited[W->AdjV] = true;
				Enqueue(Q, W->AdjV);
			}
	}
	DestroyQueue(Q);
}

