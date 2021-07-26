/**
 * LZW (Lempel-Ziv-Welch) data compression in java code
 */
public class LZW {
  private static final int R = 256;        // number of input chars
  private static final int L = 4096;       // number of codewords = 2^W
  private static final int W = 12;         // codeword width

  // Do not instantiate.
  private LZW() { }

  public static void compress() { 
    String input = BinaryStdIn.readString();
    TST<Integer> st = new TST<Integer>();

    // since TST is not balanced, it would be better to insert in a different order
    for (int i = 0; i < R; i++)
      st.put("" + (char) i, i);

    int code = R+1;  // R is codeword for EOF

    while (input.length() > 0) {
      String s = st.longestPrefixOf(input);  // Find max prefix match s.
      BinaryStdOut.write(st.get(s), W);      // Print s's encoding.
      int t = s.length();
      if (t < input.length() && code < L)    // Add s to symbol table.
        st.put(input.substring(0, t + 1), code++);
      input = input.substring(t);            // Scan past s in input.
    }
    BinaryStdOut.write(R, W);
    BinaryStdOut.close();
  } 

  public static void expand() {
    String[] st = new String[L];
    int i; // next available codeword value

    // initialize symbol table with all 1-character strings
    for (i = 0; i < R; i++)
      st[i] = "" + (char) i;
    st[i++] = "";                        // (unused) lookahead for EOF

    int codeword = BinaryStdIn.readInt(W);
    if (codeword == R) return;           // expanded message is empty string
    String val = st[codeword];

    while (true) {
      BinaryStdOut.write(val);
      codeword = BinaryStdIn.readInt(W);
      if (codeword == R) break;
      String s = st[codeword];
      if (i == codeword) s = val + val.charAt(0);   // special case hack
      if (i < L) st[i++] = val + s.charAt(0);
      val = s;
    }
    BinaryStdOut.close();
  }

  public static void main(String[] args) {
    if      (args[0].equals("-")) compress();
    else if (args[0].equals("+")) expand();
  }

}
