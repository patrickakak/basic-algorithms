/**
 * Quicksort in java code
 */
public class Quick {

  private static int partition(Comparable[] a, int lo, int hi) {

    int i = lo, j = hi+1;
    while (true) {

      while (less(a[++i], a[lo]))      // find item on left to swap
        if (i == hi) break;

      while (less(a[lo], a[--j]))      // find item on right to swap
        if (j == lo) break;

      if (i >= j) break;               // check if pointers cross
      exch(a, i, j);
    }

    exch(a, lo, j);                    // swap with partitioning item
    return j;        // return index of item now known to be in place
  }

  public static void sort(Comparable[] a) {
    StdRandom.shuffle(a);              // shuffle needed for performace
    sort(a, 0, a.length - 1);          // guarantee
  }

  private static void sort(Comparable[] a, int lo, int hi) {

    // Even quicksort has too much overhead for tiny subarrays
    // Cutoff to insertion sort for ~ 10 items
    // Note: could delay insertion sort until one pass at end
    if (hi <= lo + CUTOFF - 1) {
      Insertion.sort(a, lo, hi);
      return;
    }
    
    int m = medianOf3(a, lo, lo + (hi - lo)/2, hi);
    swap(a, lo, m);

    int j = partition(a, lo, hi);
    sort(a, lo, j-1);
    sort(a, j+1, hi);
  }

}

