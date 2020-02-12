/**
 * Operation set of Binary Search Tree (BST) 
 *
 * So how to determine if a tree is a BST or not?, we can use inorder 
 * traversal to help us, set a last variable to store the last element (L) 
 * popped out stack and compare it with the current element (X) popped out, 
 * if X is lesser than L, then an error occured 
 */
#define EMPTY NULL
#define SIZE 5
typedef int ElementType;
typedef strcut TreeNode *PtrToTreeNode;
typedef PtrToTreeNode BinTree;
typedef BinTree Position;
struct TreeNode {
	BinTree Left, Right;
	ElementType Data;
	int Count;
};
Position Find(BinTree BST, ElementType X) {
	if (!BST) return EMPTY;
	if (X < BST->Data) return Find(BST->Left, X);
	else if (X > BST->Data) return Find(BST->Right, X);
	else return BST;
}
Position IterFind(BinTree BST, ElementType X) {
	while (BST)
		if (X < BST->Data) BST = BST->Left;
		else if (X > BST->Data) BST = BST->Right;
		else return BST;
	return EMPTY;
}
Position FindMin(BinTree BST) {
	if (!BST) return EMPTY;
	if (!BST->Left) return BST;
	else return FindMin(BST->Left);
}
Position FindMax(BinTree BST) {
	if (BST)
		while (BST->Right)
			BST = BST->Right;
	return BST;
}
PtrToTreeNode MakeNode(ElementType X) {
	PtrToTreeNode New = (BinTree) malloc(sizeof(struct TreeNode));
	New->Data = X;
	New->Count = 1;
	New->Left = New->Right = NULL;
	return New;
}
BinTree Insert(BinTree BST, ElementType X) {
	if (!BST) BST = MakeNode(X);
	else {
		if (X < BST->Data) BST->Left = Insert(BST->Left, X);
		else if (X > BST->Data) BST->Right = Insert(BST->Right, X);
		else BST->Count++;
	}
	return BST;
}
BinTree Delete(BinTree BST, ElementType X) {
	Position Tmp;
	if (!BST) printf("Couldn't find the element!\n");
	else if (X < BST->Data)	BST->Left = Delete(BST->Left, X);
	else if (X > BST->Data)	BST->Right = Delete(BST->Right, X);
	else if (BST->Count > 1) BST->Count--;
	else {
		if (BST->Left && BST->Right) {
			Tmp = FindMax(BST->Left);
			BST->Data = Tmp->Data;
			BST->Left = Delete(BST->Left, BST->Data);
		} else {
			Tmp = BST;
			if (!BST->Left) BST = BST->Right;
			else if (!BST->Right) BST = BST->Left;
			free(Tmp);
		}
	}
	return BST;
}
