/***************************************************
 *          IMPLEMENTATION OF AVL-TREE
 **************************************************/
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct AVLNode *Position;
typedef Position AVLTree;
typedef AVLTree BinTree;
typedef int ElementType;
struct AVLNode {
	ElementType Data;
	AVLTree Left; 	/* Point to left subtree */
	AVLTree Right; 	/* Point to right subtree */
	int Height; 	/* Height of tree */
};

int GetHeight(BinTree BT)
{
	int HL, HR, MaxH;

	if (BT) {
		HL = GetHeight(BT->Left);	/* Get height of left subtree */
		HR = GetHeight(BT->Right);
		MaxH = HL > HR ? HL : HR; 	/* Take the bigger value */
		return (MaxH + 1); 	/* Return depth of tree */
	} else
		return 0;	/* Empty subtree is height of 0 */
}

/*************************************************************************/
/* Implementation of single left rotation and double right left rotation */
/*************************************************************************/

/* A must have a left childnode B: single left rotation of A and B, update
 * height of both tree and return root node B then */
AVLTree LL(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = 1 + max(GetHeight(A->Left), GetHeight(A->Right));
	B->Height = 1 + max(GetHeight(B->Left), A->Height);
	return B;
}

AVLTree RR(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = max(GetHeight(B->Left), A->Height) + 1;
	return B;
}

/* A must have childnode B (left) and C (right):
 * do single rotation twice and return root C */
AVLTree LR(AVLTree A)
{
	/* Single left rotation of B and C, return C */
	A->Left = RR(A->Left);
	/* Single right rotation of A and C, return C */
	return LL(A);
}

AVLTree RL(AVLTree A)
{
	A->Right = LL(A->Right);
	return RR(A);
}

/* Insert X into AVL tree and return the re-arranged AVL tree */
AVLTree Insert(AVLTree T, ElementType X)
{
	if (!T) { 	/* Create a new node if empty */
		T = (AVLTree) malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	} else if (X < T->Data) {	/* Insert it into left subtree of T */
		T->Left = Insert(T->Left, X);
		if (GetHeight(T->Left)-GetHeight(T->Right) == 2) {
			if (X < T->Left->Data)
				T = LL(T);
			else
				T = LR(T);
		}
	} else if (X > T->Data) {
		T->Right = Insert(T->Right, X);
		if (GetHeight(T->Left)-GetHeight(T->Right) == -2) {
			if (X > T->Right->Data)
				T = RR(T);
			else
				T = RL(T);
		}
	}
	/* else X equals T->Data, no need do insertion */
	/* Update height of AVL tree */
	T->Height = 1 + max(GetHeight(T->Left), GetHeight(T->Right));
	return T;
}

Position FindMax(BinTree BST)
{
	/* Keep seeking the rightest leaf node */
	if (BST)
		while (BST->Right)
			BST = BST->Right;
	return BST;
}

AVLTree Delete(AVLTree T, ElementType X)
{
	Position Tmp;
	if (!T)
		printf("no such node\n");
	else if (X < T->Data)
		T->Left = Delete(T->Left, X);
	else if (X > T->Data)
		T->Right = Delete(T->Right, X);
	else {
		if (T->Left && T->Right) {
			Tmp = FindMax(T->Left);
			T->Data = Tmp->Data;
			T->Left = Delete(T->Left, T->Data);
		} else {
			Tmp = T;
			if (!T->Left)
				T = T->Right;
			else if (!T->Right)
				T = T->Left;
			free(Tmp);
		}
	}
	return T;
}

int main()
{
	return 0;
}


