/**
 * 3-way string quicksort in java code
 *   - Uses ~2NlnN character compares on average for random strings
 *   - Avoids re-comparing long common prefixes
 *   - Has a short inner loop
 *   - Is cache-friendly
 *   - Is in-place
 */
public class Quick3string {

  private static void sort(String[] a) {
    sort(a, 0, a.length-1, 0);
  }

  private static void sort(String[] a, int lo, int hi, int d) {

    if (hi <= lo) return;
    int lt = lo, gt = hi;
    int v = charAt(a[lo], d);
    int i = lo + 1;
    while (i <= gt) {
      int t = charAt(a[i], d);
      if      (t < v) exch(a, lt++, i++);
      else if (t > v) exch(a, i, gt--);
      else            i++;
    }

    sort(a, lo, lt-1, d);
    if (v >= 0) sort(a, lt, gt, d+1);
    sort(a, gt+1, hi, d);
  }

}

