typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* To create a stack with headnode, return the head */
Stack CreateStack()
{
	Stack S;

	S = (Stack) malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsEmpty(Stack S)
{
	return (S->Next == NULL);
}

bool Push(Stack S, ElementType X)
{
	PtrToSNode TmpCell;

	TmpCell = (PtrToSNode) malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}

/* Delete and return the top element of stack */
ElementType Pop(Stack S)
{
	PtrToSNode FirstCell;
	ElementType TopElem;

	if (IsEmpty(S)) {
		printf("Empty stack");
		return ERROR;
	} else {
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}

