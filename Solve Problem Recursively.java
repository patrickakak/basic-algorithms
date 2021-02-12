# When you meet a tree problem, ask yourself two questions: Can you determine
# some parameters to help the node know its answer? Can you use these parameters
# and the value of the node itself to determine what should be the parameters
# passed to its children? If the answers are both yes, try to solve this problem
# using a "top-down" recursive solution.

private int answer; // don't forget to initialize answer before call maximum_depth
private void maximum_depth(TreeNode root, int depth) {
  if (root == null) {
    return;
  }
  if (root.left == null && root.right == null) {
    answer = Math.max(answer, depth);
  }
  maximum_depth(root.left, depth + 1);
  maximum_depth(root.right, depth + 1);
}


# Or, you can think of the problem in this way: for a node in a tree, if you know
# the answer of its children, can you calculate the answer of that node? If the
# answer is yes, solving the problem recursively using a bottom up approach might
# be a good idea.

public int maximum_depth(TreeNode root) {
  if (root == null) {
    return 0;                                     // return 0 for null node
  }
  int left_depth = maximum_depth(root.left);
  int right_depth = maximum_depth(root.right);
  return Math.max(left_depth, right_depth) + 1;   // return depth of the subtree rooted at root
}
