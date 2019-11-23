/**
 * Level order traversal
 */
void LevelOrderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;

	if (!BT) return;	/* Empty tree, do nothing */
	Q = CreatQueue(MaxSize);	/* Create and initialize queue */
	Enqueue(Q, BT);
	while (!IsEmptyQ(Q)) {
		T = Dequeue(Q);
		printf("%d", T->Data);
		if (T->Left)
			Enqueue(Q, T->Left);
		if (T->Right)
			Enqueue(Q, T->Right);
	}
}

