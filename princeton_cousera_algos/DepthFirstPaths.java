/**
 * Depth first paths in java code
 */
public class DepthFirstPaths {

  private boolean[] marked;
  private int[] edgeTo;
  private final int s;

  public DepthFirstPaths(Graph G, int s) {
    this.s = s;
    edgeTo = new int[G.V()];
    marked = new boolean[G.V()];
    validateVertex(s);
    dfs(G, s);
  }

  private void dfs(Graph G, int v) {
    marked[v] = true;
    for (int w : G.adj(v)) {
      if (!marked[w]) {
        edgeTo[w] = v;
        dfs(G, w);
      }
    }
  }

}

