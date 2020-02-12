/***************************************************
 *          IMPLEMENTATION OF AVL-TREE
 **************************************************/
typedef struct AVLNode *Position;
typedef Position AVLTree;
typedef AVLTree BinTree;
typedef int ElementType;
struct AVLNode {
	ElementType Data;
	AVLTree Left, Right;
	int Height;
};
int GetHeight(BinTree BT) {
	if (BT) {
		int HL = GetHeight(BT->Left);
		int HR = GetHeight(BT->Right);
		int MaxH = HL > HR ? HL : HR;
		return (MaxH + 1);
	} else return 0;
}
AVLTree LL(AVLTree A) {
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = 1 + max(GetHeight(A->Left), GetHeight(A->Right));
	B->Height = 1 + max(GetHeight(B->Left), A->Height);
	return B;
}
AVLTree RR(AVLTree A) {
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = max(GetHeight(B->Left), A->Height) + 1;
	return B;
}
AVLTree LR(AVLTree A) {
	A->Left = RR(A->Left);
	return LL(A);
}
AVLTree RL(AVLTree A) {
	A->Right = LL(A->Right);
	return RR(A);
}
AVLTree Insert(AVLTree T, ElementType X) {
	if (!T) {
		T = (AVLTree) malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	} else if (X < T->Data) {
		T->Left = Insert(T->Left, X);
		if (GetHeight(T->Left)-GetHeight(T->Right) == 2) {
			if (X < T->Left->Data) T = LL(T);
			else T = LR(T);
		}
	} else if (X > T->Data) {
		T->Right = Insert(T->Right, X);
		if (GetHeight(T->Left)-GetHeight(T->Right) == -2) {
			if (X > T->Right->Data) T = RR(T);
			else T = RL(T);
		}
	}
	T->Height = 1 + max(GetHeight(T->Left), GetHeight(T->Right));
	return T;
}
Position FindMax(BinTree BST) {
	if (BST)
		while (BST->Right)
			BST = BST->Right;
	return BST;
}
AVLTree Delete(AVLTree T, ElementType X) {
	if (!T) printf("no such node\n");
	else if (X < T->Data) T->Left = Delete(T->Left, X);
	else if (X > T->Data) T->Right = Delete(T->Right, X);
	else {
		if (T->Left && T->Right) {
			Tmp = FindMax(T->Left);
			T->Data = Tmp->Data;
			T->Left = Delete(T->Left, T->Data);
		} else {
			Position Tmp = T;
			if (!T->Left) T = T->Right;
			else if (!T->Right) T = T->Left;
			free(Tmp);
		}
	}
	return T;
}
