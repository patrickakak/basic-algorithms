typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
#define ERROR NULL
Position Find(List L, ElementType X) {
	Position p = L;
	while (p && p->Data != X) p = p->Next;
	if (p) return p;
	else return ERROR;
}
bool Insert(List L, ElementType X, Position P) {
	Position pre, tmp;
	for (pre = L; pre && pre->Next != P; pre = pre->Next) ;
	if (pre == NULL) {
		printf("Position of insertion error");
		return false;
	} else {
		tmp = (Position) malloc(sizeof(struct LNode));
		tmp->Data = X; 
		tmp->Next = P;
		pre->Next = tmp;
		return true;
	}
}
bool Delete(List L, Position P) {
	Position tmp, pre;
	for (pre = L; pre && pre->Next != P; pre = pre->Next) ;
	if (pre == NULL || P == NULL) {
		printf("Deletion position error");
		return false;
	} else {
		pre->Next = P->Next;
		free(P);
		return true;
	}
}
