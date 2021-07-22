/**
 * Shortest paths in edge-weighted DAGs
 *   since an edge-weighted digraph has no directed cycles is easier to 
 *   find shortest paths that in a general digraph, and edge weights can 
 *   be negative (by making the weights negative, we can get longest paths)
 */
public class AcyclicSP {

  private DirectedEdge[] edgeTo;
  private double[] distTo;

  public AcyclicSP(EdgeWeightedDigraph G, int s) {

    edgeTo = new DirectedEdge[G.V()];
    distTo = new double[G.V()];

    for (int v = 0; v < G.V(); v++)
      distTo[v] = Double.POSITIVE_INFINITY;
    distTo[s] = 0.0;

    Topological topological = new Topological(G);
    for (int v : topological.order())
      for (DirectedEdge e : G.adj(v))
        relax(e);
  }

}

