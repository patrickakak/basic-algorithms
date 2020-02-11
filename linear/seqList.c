typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};
List MakeEmpty() {
	List L = (List) malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}
#define ERROR -1
Position Find(List L, ElementType X) {
	Position i = 0;
	while (i <= L->Last && L->Data[i] != X) i++;
	if (i > L->Last) return ERROR;
	else return i;
}
bool Insert(List L, ElementType X, Position P) {
	if (L->Last == MAXSIZE-1) {
		printf("Full list"); 
		return false; 
	}  
	if (P < 0 || P > L->Last+1) {
		printf("Illegal position");
		return false; 
	} 
	for (Position i = L->Last; i >= P; i--)
		L->Data[i+1] = L->Data[i];
	L->Data[P] = X;
	L->Last++;
	return true; 
}
bool Delete(List L, Position P) {
	if (P < 0 || P > L->Last) {
		printf("No such L[%d] element", P);
		return false; 
	}
	for (Position i = P+1; i <= L->Last; i++)
		L->Data[i-1] = L->Data[i];
	L->Last--;
	return true;
}
