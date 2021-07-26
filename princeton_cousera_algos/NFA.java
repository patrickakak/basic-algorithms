/**
 * NFA simulation of regexp in java code
 *   T=O(MN)
 */
public class NFA {

  private char[] re;       // match transition
  private Digraph G;       // epsilon transition digraph
  private int M;           // number of states

  public NFA(String regexp) {
    M  = regexp.length();
    re = regexp.toCharArray();
    G  = buildEpsilonTransitionDigraph();
  }

  public boolean recognizes(String txt) {
    Bag<Integer> pc = new Bag<Integer>();
    DirectedDFS dfs = new DirectedDFS(G, 0);
    
    // states reachable from start by ε-transitions
    for (int v = 0; v < G.V(); v++)
      if (dfs.marked(v)) pc.add(v);

    for (int i = 0; i < txt.length(); i++) {
      Bag<Integer> match = new Bag<Integer>();
      // states reachable after scanning past txt.charAt(i)
      for (int v : pc) {
        if (v == M) continue;
        if ((re[v] == txt.charAt(i)) || re[v] == '.')
          match.add(v+1);
      }

      dfs = new DirectedDFS(G, match);
      pc = new Bag<Integer>();
      // follow ε-transitions
      for (int v = 0; v < G.V(); v++)
        if (dfs.marked(v)) pc.add(v);
    }

    // accept if can end in state M
    for (int v : pc)
      if (v == M) return true;
    return false;
  }

  private Digraph buildEpsilonTransitionDigraph() {
    Digraph G = new Digraph(M+1);
    Stack<Integer> ops = new Stack<Integer>();
    for (int i = 0; i < M; i++) {
      int lp = i;

      // left parentheses and |
      if (re[i] == '(' || re[c] == '|') ops.push(i);

      else if (re[i] == ')') {
        int or = ops.pop();
        if (re[or] == '|') {
          lp = ops.pop();
          G.addEdge(lp, or+1);
          G.addEdge(or, i);
        }
        else lp = or;
      }

      // closure (needs 1-character lookahead)
      if (i < M-1 && re[i+1] == '*') {
        G.addEdge(lp, i+1);
        G.addEdge(i+1, lp);
      }

      // metasymbols
      if (re[i] == '(' || re[i] == '*' || re[i] == ')')
        G.addEdge(i, i+1);
    }
    return G;
  }

}

