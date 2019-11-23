/**
 * In Order Traversal
 */
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int Nv; 	/* Number of visitation */
};

/* Inorder traversal (recursive) */
void InOrderTraversal(BinTree BT)
{
	if (BT) {
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}

/* Non-recursive binary tree traversals
 * Brief algorithm:
 *   1. Encounter a node, push it into the stack and 
 *      go through its left subtree
 *   2. After the left subtree has been traversed, 
 *      pop the node out and access it
 *   3. Then traverse the right subtree of the node 
 *      by its right pointer(InOrderTraversal)
 */
void InOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);

	/* If T is not NULL or there is(are) element(s) inside the stack, 
	 * go on with the loop, i.e. if T is NULL and stack is empty, 
	 * it ends(or never enter the loop)
	 */
	while (T || !IsEmpty(S)) {
		while (T) { 	/* Find the leftest node */
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S); 	/* Second time to visit it */
			printf("%5d", T->Data);
			T = T->Right; 	/* Reset root and do the same */
		}
	}
}

