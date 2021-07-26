/**
 * Longest repeated substring in java code
 */
public String lrs(String s) {

  int N = s.length();

  String[] suffixes = new String[N];
  for (int i = 0; i < N; i++)
    suffixes[i] = s.substring(i, N);

  Arrays.sort(suffixes);

  String lrs = "";
  for (int i = 0; i < N-1; i++) {

    // find LCP (longest common prefix) between adjacent 
    // suffixes in sorted order
    int len = lcp(suffixes[i], suffixes[i+1]);
    if (len > lrs.length())
      lrs = suffixes[i].substring(0, len);
  }
  return lrs;
}

