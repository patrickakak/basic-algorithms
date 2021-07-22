/**
 * Prim's algorithm: lazy implementation (there's an eager version which 
 *   uses Indexed priority queue to do the job)
 *
 *   T=O(ElgE), S=O(E) in the worst case
 *
 * Running time:
 *   depends on PQ implementation: V inserts, V delete-min, E decrese-key
 * 
 *   PQ implementation   insert    delete-min    decrease-key    total
 *  -------------------------------------------------------------------
 *      array              1           V             1            V^2
 *    binary heap         lgV         lgV           lgV          ElgV
 *    d-way heap          lgdV       dlgdV         lgdV          ElgV
 *   Fibonacci heap        1          lgV            1          E + VlgV
 */
public class LazyPrimMST {

  private boolean[] marked;   // MST vertices
  private Queue<Edge> mst;    // MST edges
  private MinPQ<Edge> pq;     // PQ of edges

  public LazyPrimMST(WeightedGraph G) {

    pq = new MinQP<Edge>();
    mst = new Queue<Edge>();
    marked = new boolean[G.V()];
    visit(G, 0);              // assume G is connected

    while (!pq.isEmpty()) {
      Edge e = pq.delMin();
      int v = e.either(), w = e.other(v);
      if (marked[v] && marked[w]) continue;
      mst.enqueue(e);
      if (!marked[v]) visit(G, v);
      if (!marked[w]) visit(G, w);
    }
  }

  private void visit(WeightedGraph G, int v) {
    marked[v] = true;
    for (Edge e : G.adj(v))
      if (!marked[e.other(v)])
        pq.insert(e);
  }

  public Iterable<Edge> mst() {  return mst;  }

}

