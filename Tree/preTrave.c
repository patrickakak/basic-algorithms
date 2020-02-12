/**
 * Pre Order Traversal
 */
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left, Right;
	int Nv;
};
void PreOrderTraversal(BinTree BT) {
	if (BT) {
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}
void PreOrderTraversal(BinTree BT) {
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);
	while (T || !IsEmpty(S)) {
		while (T) {
			Push(S, T);
			printf("%5d", T->Data);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			T = T->Right;
		}
	}
}
