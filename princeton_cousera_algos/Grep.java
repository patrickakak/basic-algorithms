/**
 * Grep (Generalized regular expression print) utility in Unix in java code
 *                       KMP            grep             Java
 * ---------------------------------------------------------------
 *   pattern       |    string           RE             program
 *   parser        |  unnecessary    check if legal   check if legal
 * compiler output |     DFA             NFA             byte code
 *   simulator     |  DFA simulator    NFA simulator      JVM
 */
public class GREP {

  public static void main(String[] args) {
    // contains RE as a substring
    String regexp = "(.*" + args[0] + ".*)";
    NFA nfa = new NFA(regexp);
    while (StdIn.hasNextLine()) {
      String line = StdIn.readLine();
      if (nfa.recognizes(line))
        StdOut.println(line);
    }
  }

}

