/**
 * Left-leaning red-black BSTs (LLRB in short)
 *   Represent 2-3 tree as a BST
 *   Use "internal" left-leaning links as "glue" for 3-nodes
 * 
 *   Definition:
 *     No node has two red links connected to it
 *     Every path from root to null link has the same number of black links
 *     Red links lean left
 */
public class BST<Key extends Comparable<Key>, Value> {

  private Node root;
  private static final boolean RED   = true;
  private static final boolean BLACK = false;

  private class Node {
    Key key;
    Value val;
    Node left, right;
    boolean color;   // color of parent link
  }

  private boolean isRed(Node x) {
    if (x == null) return false;
    return x.color == RED;
  }

  // Search is the same as for elementary BST, most other ops (e.g., floor, 
  // iteration, selection) are also identical
  public Value get(Key key) {
    Node x = root;
    while (x != null) {
      int cmp = key.compareTo(x.key);
      if      (cmp < 0) x = x.left;
      else if (cmp > 0) x = x.right;
      else              return x.val;
    }
    return null;
  }

  private Node rotateLeft(Node h) {
    assert isRed(h.right);
    Node x = h.right;
    h.right = x.left;
    x.left = h;
    x.color = h.color;
    h.color = RED;
    return x;
  }

  private Node rotateRight(Node h) {
    assert isRed(h.left);
    Node x = h.left;
    h.left = x.right;
    x.right = h;
    x.color = h.color;
    h.color = RED;
    return x;
  }

  private void flipColors(Node h) {
    assert !isRed(h);
    assert isRed(h.left);
    assert isRed(h.right);
    h.color = RED;
    h.left.color  = BLACK;
    h.right.color = BLACK;
  }

  private Node put(Node h, Key key, Value val) {

    // insert at bottom (and color red)
    if (h == null) return new Node(key, val, RED);
    int cmp = key.compareTo(h.key);
    if      (cmp  < 0) h.left  = put(h.left,  key, val);
    else if (cmp  > 0) h.right = put(h.right, key, val);
    else               h.val = val;

    if (isRed(h.right) && !isRed(h.left))     h = rotateLeft(h);  // lean left
    if (isRed(h.left)  && isRed(h.left.left)) h = rotateRight(h); // balance 4-node
    if (isRed(h.left)  && isRed(h.right))     flipColors(h);      // split 4-node

    return h;
  }

}

