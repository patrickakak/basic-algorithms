/**
 * Hamilton path in java code
 */
public class HamiltonPath {

  private boolean[] marked;     // vertices on current path
  private int count = 0;        // number of Hamiltonian paths

  public HamiltonPath(Graph G) {
    marked = new boolean[G.V()];
    for (int v = 0; v < G.V(); v++)
      dfs(G, v, 1);
  }

  private void dfs(Graph G, int v, int depth) {
    marked[v] = true;
    if (depth == G.V()) count++;

    for (int w : G.adj(v))
      if (!marked[w]) dfs(G, w, depth+1);

    marked[v] = false;
  }

}

