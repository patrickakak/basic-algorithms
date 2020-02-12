/**
 * Level order traversal
 */
void LevelOrderTraversal(BinTree BT) {
	queue<BinTree> Q;
	BinTree T;
	if (!BT) return;
	Enqueue(Q, BT);
	while (!IsEmptyQ(Q)) {
		T = Dequeue(Q);
		printf("%d", T->Data);
		if (T->Left) Enqueue(Q, T->Left);
		if (T->Right) Enqueue(Q, T->Right);
	}
}
