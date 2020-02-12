/**
 * In Order Traversal
 */
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left, Right;
	int Nv;
};
// recursive
void InOrderTraversal(BinTree BT) {
	if (BT) {
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}
// iterative
void InOrderTraversal(BinTree BT) {
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);
	while (T || !IsEmpty(S)) {
		while (T) {
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			printf("%5d", T->Data);
			T = T->Right;
		}
	}
}
