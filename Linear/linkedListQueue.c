typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;
struct QNode {
	Position Front, Rear;
	int MaxSize;
};
typedef struct QNode *Queue;
bool IsEmpty(Queue Q) {
	return (Q->Front == NULL);
}
ElementType Dequeue(Queue Q) {
	if (IsEmpty(Q)) {
		printf("Empty queue");
		return ERROR;
	} else {
		Position FrontCell = Q->Front;
		if (Q->Front == Q->Rear) Q->Front = Q->Rear = NULL;
		else Q->Front = Q->Front->Next;
		ElementType FrontElem = FrontCell->Data;
		free(FrontCell);
		return FrontElem;
	}
}
