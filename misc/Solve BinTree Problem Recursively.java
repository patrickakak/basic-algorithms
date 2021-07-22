// When you meet a tree problem, ask yourself two questions: Can you determine
// some parameters to help the node know its answer? Can you use these parameters
// and the value of the node itself to determine what should be the parameters
// passed to its children? If the answers are both yes, try to solve this problem
// using a "top-down" recursive solution.

// 1. return if root is null
// 2. if root is a leaf node:
// 3.     answer = max(answer, depth)         // update the answer if needed
// 4. maximum_depth(root.left, depth + 1)     // call the function recursively for left child
// 5. maximum_depth(root.right, depth + 1)    // call the function recursively for right child

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


// Or, you can think of the problem in this way: for a node in a tree, if you know
// the answer of its children, can you calculate the answer of that node? If the
// answer is yes, solving the problem recursively using a bottom up approach might
// be a good idea.

// 1. return specific value for null node
// 2. left_ans = bottom_up(root.left)      // call function recursively for left child
// 3. right_ans = bottom_up(root.right)    // call function recursively for right child
// 4. return answers                       // answer <-- left_ans, right_ans, root.val

public int maximum_depth(TreeNode root) {
  if (root == null) {
    return 0;                                     // return 0 for null node
  }
  int left_depth = maximum_depth(root.left);
  int right_depth = maximum_depth(root.right);
  return Math.max(left_depth, right_depth) + 1;   // return depth of the subtree rooted at root
}
