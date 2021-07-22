/**
 * 3-way quicksort (the Dutch national flag problem) [Edsger Dijkstra]
 *   used in qsort in libc, java.util.Arrays.sort...
 *   handle well in duplicat keys situations. Actually, Randomised 
 *   quicksort with 3-way partitioning reduces running time from 
 *   linearithmic to linear in broad class of applications.
 */
private static void sort(Comparable[] a, int lo, int hi) {

  if (hi <= lo) return;
  int lt = lo, gt = hi;
  Comparable v = a[lo];
  int i = lo;
  while (i <= gt) {
    int cmp = a[i].compareTo(v);
    if      (cmp < 0) exch(a, lt++, i++);
    else if (cmp > 0) exch(a, i, gt--);
    else              i++;
  }

  sort(a, lo, lt - 1);
  sort(a, gt + 1, hi);

}

