/**
 * Mergesort in java code
 */
public class Merge {

  private static void merge(Comparable[] a, Comparable[] aux, int lo, int mid, int hi) {

    assert isSorted(a, lo, mid);    // precondition: a[lo..mid]   sorted
    assert isSorted(a, mid+1, hi);  // precondition: a[mid+1..hi] sorted

    for (int k = lo; k <= hi; k++)
      aux[k] = a[k];

    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
      if      (i > mid)              a[k] = aux[j++];
      else if (j > hi)               a[k] = aux[i++];
      else if (less(aux[j], aux[i])) a[k] = aux[j++];
      else                           a[k] = aux[i++];
    }

    assert isSorted(a, lo, hi);     // postcondition: a[lo..hi] sorted
  }

  private static void sort(Comparable[] a, Comparable[] aux, int lo, int hi) {

    // User insertion sort for small subarrays
    //   - Mergesort has too much overhead for tiny subarrays
    //   - Cutoff to insertion sort for ~ 7 items
    if (hi <= lo + CUTOFF - 1) {
      Insertion.sort(a, lo, hi);
      return;
    }
    int mid = lo + (hi - lo) / 2;
    sort (a, aux, lo, mid);
    sort (a, aux, mid+1, hi);

    // Stop if already sorted
    //   - Is biggest item in first half <= smallest item in second half?
    //   - Helps for partially-ordered arrays
    if (!less(a[mid+1], a[mid])) return;
    merge(a, aux, lo, mid, hi);
  }

  public static void sort(Comparable[] a) {
    aux = new Comparable[a.length];
    sort(a, aux, 0, a.length - 1);
  }

}

