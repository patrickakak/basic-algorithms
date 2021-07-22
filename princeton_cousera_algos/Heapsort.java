/**
 * Heapsort in java code
 */
public class Heap {

  public static void sort(Comparable[] pq) {
    
    int N = pq.length;
    // build heap using bottom-up method
    for (int k = N/2; k >= 1; k--)
      sink(pq, k, N);
    while (N > 1) {
      exch(pq, 1, N);
      sink(pq, 1, --N); 
    }
  }

  private static void sink(Comparable[] pq, int k, int N) {
    /* as before */
  }

  private static boolean less(Comparable[] pq, int i, int j) {
    /* as before but convert from 1-based indexing to 0-base indexing */
  }

  private static void exch(Comparable[] pq, int i, int j) {
    /* as before but convert from 1-based indexing to 0-base indexing */
  }

}

