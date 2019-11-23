/**
 * Post Order Traversal
 */
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
	int Nv; 	/* Number of visitation */
};

/* Postorder traversal (recursive) */
void PostOrderTraversal(BinTree BT)
{
	if (BT) {
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}

/* Non-recursive postorder traversals */
void PostOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);

	while (T || !IsEmpty(S)) {
		while (T) {
			T->Nv = 1;
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S); T->Nv++;
			if (!T->Right)
				T->Nv++; 	/* If the right subtree is NULL */
			if (T->Nv == 3) {
				printf("%5d", T->Data);
				T = NULL;
			} else {
				Push(S, T);
				T = T->Right;
			}
		}
	}
}

