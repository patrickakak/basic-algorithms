typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};

/* Initialization */
List MakeEmpty()
{
	List L;

	L = (List) malloc(sizeof(struct LNode));
	L->Last = -1;

	return L;
}

/* Find */
#define ERROR -1

Position Find(List L, ElementType X)
{
	Position i = 0;

	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (i > L->Last)
		return ERROR; 	/* Couldn't find X, return ERROR */
	else
		return i; 	/* Find X, return the position */
}

/* Insert a X in front of L[P] */
bool Insert(List L, ElementType X, Position P)
{
	Position i;

	if (L->Last == MAXSIZE-1) {
		printf("Full list"); 
		return false; 
	}  
	if (P < 0 || P > L->Last+1) {
		printf("Illegal position");
		return false; 
	} 
	for (i = L->Last; i >= P; i--)
		L->Data[i+1] = L->Data[i]; 	/* Move afterwards */
	L->Data[P] = X; 	/* New element insertion */
	L->Last++; 	/* Still points to the last element */
	return true; 
}

/* Delete L[P] from the List L */
bool Delete(List L, Position P)
{
	Position i;

	if (P < 0 || P > L->Last) {
		printf("No such L[%d] element", P);
		return false; 
	}
	for (i = P+1; i <= L->Last; i++)
		L->Data[i-1] = L->Data[i]; 	/* Move forwards (P+1 ~ Last) */
	L->Last--; 	/* Still points to the last element */
	return true;
}

