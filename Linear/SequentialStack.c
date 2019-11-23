typedef int Position;
struct SNode {
	ElementType *Data; 	/* Array to store elements */
	Position Top; 	/* Top pointer of stack */
	int MaxSize; 	/* Max capacity of stack */
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack) malloc(sizeof(struct SNode));
	S->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull(Stack S)
{
	return (S->Top == S->MaxSize-1);
}

bool Push(Stack S, ElementType X)
{
	if (IsFull(S)) {
		printf("Full stack");
		return false;
	} else {
		S->Data[++(S->Top)] = X;
		return true;
	}
}

bool IsEmpty(Stack S)
{
	return (S->Top == -1);
}

ElementType Pop(Stack S)
{
	if (IsEmpty(S)) {
		printf("Empty stack");
		return ERROR; 	/* To indicate an error */
	} else
		return (S->Data[(S->Top)--]);
}

