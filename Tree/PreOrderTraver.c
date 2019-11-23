/**
 * Pre Order Traversal
 */
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int Nv; 	/* Number of visitation */
};

/* Binary tree preorder traversal (recursive) */
void PreOrderTraversal(BinTree BT)
{
	/* If BT is empty, do nothing */
	if (BT) {
		printf("%d", BT->Data); 	/* Visit the node */
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}

/* Non-recursive (i.e. iterative) preorder traversals */
void PreOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);

	while (T || !IsEmpty(S)) {
		while (T) {
			Push(S, T); 	/* First time to visit it */
			printf("%5d", T->Data);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			T = T->Right;
		}
	}
}

