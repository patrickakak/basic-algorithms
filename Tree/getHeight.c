/* Post order traversal to get the height of binary tree */
int PostOrderGetHeight(BinTree BT) {
	if (BT) {
		int HL = PostOrderGetHeight(BT->Left);
		int HR = PostOrderGetHeight(BT->Right);
		int MaxH = HL > HR ? HL : HR;
		return (MaxH + 1);
	} else return 0;
}
