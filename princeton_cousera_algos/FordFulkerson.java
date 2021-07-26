/**
 * Ford-Fulkerson algorithm to solve Maxflow-mincut problem in java code
 */
public class FordFulkerson {

  private boolean[] marked;   // true if s->v path in residual network
  private FlowEdge[] edgeTo;  // last edge on s->v path
  private double value;       // value of flow

  public FordFulkerson(FlowNetwork G, int s, int t) {

    value = 0.0;
    while (hasAugmentingPath(G, s, t)) {

      // compute bottleneck capacity
      double bottle = Double.POSITIVE_INFINITY;
      for (int v = t; v != s; v = edgeTo[v].other(v))
        bottle = Math.min(bottle, edgeTo[v].residualCapacityTo(v));

      // augment flow
      for (int v = t; v != s; v = edgeTo[v].other(v))
        edgeTo[v].addResidualFlowTo(v, bottle);

      value += bottle;
    }
  }

  private boolean hasAugmentingPath(FlowNetwork G, int s, int t) {
    edgeTo = new FlowEdge[G.V()];
    marked = new boolean[G.V()];

    Queue<Integer> q = new Queue<Integer>();
    q.enqueue(s);
    marked[s] = true;
    while (!q.isEmpty()) {
      int v = q.dequeue();

      for (FlowEdge e : G.adj(v)) {
        int w = e.other(v);
        if (e.residualCapacityTo(w) > 0 && !marked[w]) {
          edgeTo[w] = e;
          marked[w] = true;
          q.enqueue(w);
        }
      }
    }
    return marked[t];
  }

  public double value() {  return value;  }

  public boolean inCut(int v) {  return marked[v];  }

}

