/**
 * Generic algorithm (to compute SPT (i.e. shortest path tree) from s)
 *   Initialise distTo[s] = 0 and distTo[v] = oo for all other vertices
 *   Repeat until optimality conditions are satisfied:
 *     - Relax any edge
 *
 *   Single source shortest-paths implementation: cost summary
 *   algorithm        restriction      typical case  worst case  extra space
 *  ------------------------------------------------------------------------
 *  topological sort  no directed cycles    E+V        E+V           V
 *  
 *    Dijkstra        no negative weights   ElgV       ElgV          V
 *  (binary heap)
 *
 *    Bellman-Ford                           EV        EV            V
 *                    no negative cycles
 *    Bellman-Ford                          E + V      EV            V
 *    (queue-based)
 *  ------------------------------------------------------------------------
 *
 * Efficient implementations. How to choose which edge to relax?
 *   1. Dijkstras's algorithm (nonnegative weights)
 *   2. Topological sort algorithm (no directed cycles)
 *   3. Bellman-Ford algorithm (no negative cycles) 
 *
 * Dijkstra's algorithmin java code (one instance of the Generic algorithm)
 */
public class DijkstraSP {

  private DirectedEdge[] edgeTo;
  private double[] distTo;
  private IndexMinPQ<Double> pq;

  public DijkstraSP(EdgeWeightedDigraph G, int s) {

    edgeTo = new DirectedEdge[G.V()];
    distTo = new double[G.V()];
    pq = new IndexMinPQ<Double>(G.V());

    for (int v = 0; v < G.V(); v++)
      distTo[v] = Double.POSITIVE_INFINITY;
    distTo[s] = 0.0;

    pq.insert(s, 0.0);
    while (!pq.isEmpty()) {
      int v = pq.delMin();
      for (DirectedEdge e : G.adj(v))
        relax(e);
    }
  }

  private void relax(DirectedEdge e) {
    int v = e.from(), w = e.to();
    if (distTo[w] > distTo[v] + e.weight()) {
      distTo[w] = distTo[v] + e.weight();
      edgeTo[w] = e;
      if (pq.contains(w)) pq.decreaseKey(w, distTo[w]);
      else                pq.insert(w, distTo[w]);
    }
  }

}

