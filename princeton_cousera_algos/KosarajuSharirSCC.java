/**
 * Kosaraju-Sharir algorithm: intuition
 *   Reverse graph: Strong components in G are same as in G^R
 *   Kernel DAG: Contract each strong component into a single vertex
 *   Idea:
 *     - Compute topological order (reverse postorder) in kernel DAG
 *     - Run DFS, considering vertices in reverse topological order
 *   Phase:
 *     1. run DFS on G^R to compute reverse postorder
 *     2. run DFS on G, considering vertices in order given by first DFS
 */
public class KosarajuSharirSCC {

  private boolean marked[];
  private int[] id;
  private int count;

  public KosarajuSharirSCC(Digraph G) {
    marked = new boolean[G.V()];
    id = new int[G.V()];
    DepthFirstOorder dfs = new DepthFirstOorder(G.reverse());
    for (int v : dfs.reversePost()) {
      if (!marked[v]) {
        dfs(G, v);
        count++;
      }
    }
  }

  private void dfs(Digraph G, int v) {
    marked[v] = true;
    id[v] = count;
    for (int w : G.adj(v))
      if (!marked[w])
        dfs(G, w);
  }

  public boolean stronglyConnected(int v, int w) {
    return id[v] == id[w];
  }

}

