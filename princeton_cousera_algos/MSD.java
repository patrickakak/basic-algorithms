/**
 * MSD string sort in java code
 *   MSD string sort vs. quicksort for strings
 *     Disadvantages of MSD string sort:
 *       - Accesses memory "randomly" (cache inefficient)
 *       - Inner loop has a lot of instructions
 *       - Extra space for count[]
 *       - Extra space for aux[]
 *
 *     Disadvantages of quicksort:
 *       - Linearithmic number of string compares (not linear)
 *       - Has to rescan many characters in keys with long prefix matches
 */
public class MSD {

  public static void sort(String[] a) {
    aux = new = String[a.length];
    sort(a, aux, 0, a.length-1, 0);
  }

  private static void sort(String[] a, String[] aux, int lo, int hi, int d) {
    if (hi <= lo) return;

    // key-indexed counting
    int[] count = new int[R+2];
    for (int i = lo; i <= hi; i++)
      count[charAt(a[i], d) + 2]++;
    for (int r = 0; r < R+1; r++)
      count[r+1] += count[r];
    for (int i = lo; i <= hi; i++)
      aux[count[charAt(a[i], d) + 1]++] = a[i];
    for (int i = lo; i <= hi; i++)
      a[i] = aux[i - lo];

    // sort R subarrays recursively
    for (int r = 0; r < R; r++)
      sort(a, aux, lo + count[r], lo + count[r+1] - 1, d+1);
  }
}

