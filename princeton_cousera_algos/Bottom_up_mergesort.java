/**
 * Bottom-up mergesort in java code
 */
public class MergeBU {

  private static Comparable[] aux;

  private static void merge(Comparable[] a, int lo, int mid, int hi) {
    /* as before */
  }

  public static void sort(Comparable[] a) {
    int N = a.length;
    aux = new Comparable[N];

    // "lo < N-sz" to make sure that we've got two groups of elements to 
    // merge, although the latter group might be in smaller size compare 
    // to the first.
    for (int sz = 1; sz < N; sz = sz+sz)
      for (int lo = 0; lo < N-sz; lo += sz+sz)
        merge(a, lo, lo+sz-1, Math.min(lo+sz+sz-1, N-1));
  }

}
