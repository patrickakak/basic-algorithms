typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;
Stack CreateStack() {
	Stack S = (Stack) malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}
bool IsEmpty(Stack S) {
	return (S->Next == NULL);
}
bool Push(Stack S, ElementType X) {
	PtrToSNode TmpCell = (PtrToSNode) malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}
ElementType Pop(Stack S) {
	if (IsEmpty(S)) {
		printf("Empty stack");
		return ERROR;
	} else {
		PtrToSNode FirstCell = S->Next;
		ElementType TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}
