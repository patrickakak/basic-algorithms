/**
 * 1d interval serach API
 *   Use a red-black BST to guarantee performance
 * 
 * Create BST, where each node stores an interval (lo, hi):
 *   - Use left endpoint as BST key
 *   - Store max endpoint in subtree rooted at node
 * 
 * To insert an interval (lo, hi):
 *   - Insert into BST, using lo as the key
 *   - Update max in each node on search path
 *
 * To search for any one interval that intersects query interval (lo, hi):
 *   - If interval in node intersects query interval, return it
 *   - Else if left subtree is null, go right
 *   - Else if max endpoint in left subtree is less that lo, go right
 *   - Else go left
 */
public class IntervalST<Key extends Comparable<Key>, Value> {

  IntervalST() {}

  void put(Key lo, Key hi, Value val) {}

  Value get(Key lo, Key hi) {}

  void delte(Key lo, Key hi) {}

  Iterable<Value> intersects(Key lo, Key hi) {}

}

