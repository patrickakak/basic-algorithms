/* Implimentaion of queue in linked list (without headnode):
 * Note: Front and Rear point to the first node and last node respectively 
 */ 
typedef struct Node *PtrToNode;
struct Node { 	/* Node in queue */
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
	Position Front, Rear; 	/* Pointer of the front and rear */
	int MaxSize; 	/* Max capacity of queue */
};
typedef struct QNode *Queue;

bool IsEmpty(Queue Q)
{
	return (Q->Front == NULL);
}

ElementType Dequeue(Queue Q)
{
	Position FrontCell; 
	ElementType FrontElem;

	if (IsEmpty(Q)) {
		printf("Empty queue");
		return ERROR;
	} else {
		FrontCell = Q->Front;
		if (Q->Front == Q->Rear) 	/* If there's only one element in queue */
			Q->Front = Q->Rear = NULL; 	/* Delete and reset pointer Rear */
		else 
			Q->Front = Q->Front->Next;
		FrontElem = FrontCell->Data;

		free(FrontCell); 	/* Free the space */
		return FrontElem;
	}
}

