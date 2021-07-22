/**
 * Breadth-first search
 */
public class BreadthFirstPaths {

  private boolean[] marked;
  private int[] edgeTo;
  private int[] distTo;
  ...

  private void bfs(Graph G, int s) {
    Queue<Integer> q = new Queue<Integer>();
    for (int v = 0; v < G.V(); v++)
      distTo[v] = INFINITY;
    distTo[s] = 0;
    marked[s] = true;
    q.enqueue(s);

    while (!q.isEmpty()) {
      int v = q.dequeue();
      for (int w : G.adj(v)) {
        if (!marked[w]) {
          edgeTo[w] = v;
          distTo[w] = distTo[v] + 1;
          marked[w] = true;
          q.enqueue(w);
        }
      }
    }
  }

}

