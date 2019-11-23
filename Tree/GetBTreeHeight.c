/* Post order traversal to get the height of binary tree */
int PostOrderGetHeight(BinTree BT)
{
	int HL, HR, MaxH;
	
	if (BT) {
		HL = PostOrderGetHeight(BT->Left);	/* Get height of left subtree */
		HR = PostOrderGetHeight(BT->Right);
		MaxH = HL > HR ? HL : HR; 	/* Take the bigger value */
		return (MaxH + 1); 	/* Return depth of tree */
	} else 
		return 0;	/* Empty subtree is height of 0 */
}

