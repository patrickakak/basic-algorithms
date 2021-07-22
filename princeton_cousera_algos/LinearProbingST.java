/**
 * Linear probing ST implementation
 *   Variants:
 *     Double hashing
 *       - Use linear probing, but skip a variable amount, not just 1 each time
 *       - Effectively eliminates clustering
 *       - Can allow table to become nearly full
 *       - More difficult to implement delete
 *     Cuckoo hashing
 *       - Hash key to two positions; insert key into either position; if 
 *         occupied, reinsert displaced key into its alternative position (
 *         and recur)
 *       - Constant worst case time for search
 */
public class LinearProbingHashST<Key, Value> {

  private int M = 30001;
  private Value[] vals = (Value[]) new Object[M];
  private Key[]   keys = (Key[])   new Object[M];

  private int hash(Key key) {  /* as before */  }

  public void put(Key key, Value val) {
    int i;
    for (i = hash(key); keys[i] != null; i = (i+1) % M)
      if (keys[i].equals(key))
        break;
    keys[i] = key;
    vals[i] = val;
  }

  public Value get(Key key) {
    for (int i = hash(key); keys[i] != null; i = (i+1) % M)
      if (key.equals(keys[i]))
        return vals[i];
    return null;
  }

}

