/**
 * Harvesting information
 */
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Harvester {

  pubic static void main(String[] args) {
    String regexp   = args[0];
    In in           = new In(args[1]);
    String input    = in.readAll();

    // compile() creates a Pattern (NFA) from RE
    Pattern pattern = Pattern.compile(regexp);

    // matcher() creates a Matcher (NFA simulator) from NFA and text
    Matcher matcher = pattern.matcher(input);

    // find() looks for the next match
    while (matcher.find()) {

      // group() returns the substring most recently found by find()
      StdOut.println(matcher.group());
    }
  }

}

