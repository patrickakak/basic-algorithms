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

/* Main functions: */

Position Find(BinTree BST, ElementType X) 	/* Tail recursion */
{
	if (!BST)
		return EMPTY;		/* Empty Tree */
	if (X < BST->Data)
		return Find(BST->Left, X); 	/* Go seeking in right subtree */
	else if (X > BST->Data)
		return Find(BST->Right, X); 	/* Go seeking in left subtree */
	else	/* X equals BST->Data */
		return BST; 	/* Seeking done, return the position */
}

/* Tail recursion can always be translated into loop way */
Position IterFind(BinTree BST, ElementType X)	/* Iteration */
{
	while (BST)
		if (X < BST->Data) 	/* Go seeking in right subtree */
			BST = BST->Left;
		else if (X > BST->Data) 	/* Go seeking in left subtree */
			BST = BST->Right;
		else
			return BST;
	return EMPTY;
}

/* Recursive */
Position FindMin(BinTree BST)
{
	if (!BST)
		return EMPTY;
	if (!BST->Left)
		return BST;		/* Find the leftest leaf node and return it */
	else
		return FindMin(BST->Left); 	/* Keep seeking in the left subtree */
}

/* No-recursive */
Position FindMax(BinTree BST)
{
	/* Keep seeking the rightest leaf node */
	if (BST)
		while (BST->Right)
			BST = BST->Right;
	return BST;
}

PtrToTreeNode MakeNode(ElementType X)
{
	PtrToTreeNode New;
	
	New = (BinTree) malloc(sizeof(struct TreeNode));
	New->Data = X;
	New->Count = 1;
	New->Left = New->Right = NULL;
	return New;
}

BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST) 	/* If empty, it means we've found the place to insert */
		BST = MakeNode(X);
	else { 	/* Keep finding... */
		if (X < BST->Data) 	/* Should be the left subtree to insert into */
			BST->Left = Insert(BST->Left, X);
		/* Should be the left subtree to insert into */
		else if (X > BST->Data)
			BST->Right = Insert(BST->Right, X);
		else
			BST->Count++;
		/* Otherwise X already exists, #node plus one */
	}
	return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
	Position Tmp;

	if (!BST)
		printf("Couldn't find the element!\n");
	else if (X < BST->Data)		/* Deletion happends in left subtree */
		BST->Left = Delete(BST->Left, X);
	else if (X > BST->Data)		/* Deletion happends in left subtree */
		BST->Right = Delete(BST->Right, X);
	else if (BST->Count > 1) 	/* Find it and #node>1 */
		BST->Count--;
	else { 	/* #node == 1 */
		/* Special handling of the node has two children by convert it into 
		 * a node with only a child or a leave node */
		if (BST->Left && BST->Right) {
			/* Or you can FindMin(BST->Right), try not to 
			 * change the feature of BST anyway */
			Tmp = FindMax(BST->Left);
			BST->Data = Tmp->Data;
			BST->Left = Delete(BST->Left, BST->Data);
		} else {	/* Handling of node with one or no child */
			Tmp = BST;
			if (!BST->Left)
				BST = BST->Right;
			else if (!BST->Right)
				BST = BST->Left;
			free(Tmp);
		}
	}
	return BST;
}

