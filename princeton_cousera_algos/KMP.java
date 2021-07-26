/**
 * KMP (Knoth-Morris-Pratt) algorithm in dfa (deterministic finate state 
 * automaton) implementation in java code
 *   T=O(M+N) to search for a pattern of length M in a text of length N
 */
public class KMP {

  private final int R;                 // the radix
  private final int M;                 // length of pattern
  private int[][] dfa;                 // the KMP automaton

  public KMP(String pat) {
    this.pat = pat;
    M = pat.length();
    dfa = new int[R][M];
    dfa[pat.charAt(0)][0] = 1;
    for (int X = 0, j = 1; j < M; j++) {
      for (int c = 0; c < R; c++)      // copy mismatch cases
        dfa[c][j] = dfa[c][X];
      dfa[pat.charAt(j)][j] = j+1;     // set match case
      X = dfa(pat.charAt(j)][X];       // update restart state
    }
  }

}

