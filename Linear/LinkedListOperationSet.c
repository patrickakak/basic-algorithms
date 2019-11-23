typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

/* Find */
#define ERROR NULL

Position Find(List L, ElementType X)
{
	Position p = L; 	/* p points to the first node of L */

	while (p && p->Data != X)
		p = p->Next;

	/* Or simply 'return p;' statement */
	if (p)
		return p;
	else
		return ERROR;
}

/* Insertion with a headnode */
bool Insert(List L, ElementType X, Position P)
{
	Position tmp, pre; 	/* Headnode presumably */

	/* Find the previous node of P */
	for (pre = L; pre && pre->Next != P; pre = pre->Next) ;
	if (pre == NULL) { 	/* The node pointed by P is not in L */
		printf("Position of insertion error");
		return false;
	} else { 	/* Find the prenode */
		/* Insert a newnode in front of P */
		tmp = (Position) malloc(sizeof(struct LNode));
		tmp->Data = X; 
		tmp->Next = P;
		pre->Next = tmp;
		return true;
	}
}

/* Deletion with a headnode */
bool Delete(List L, Position P)
{
	Position tmp, pre; 	/* Headnode presumably */

	/* Find the previous node of P */
	for (pre = L; pre && pre->Next != P; pre = pre->Next) ;
	if (pre == NULL || P == NULL) { 	/* The node pointed by P is not in L */ 
		printf("Deletion position error");
		return false;
	} else { 	/* Find and delete */
		pre->Next = P->Next;
		free(P);
		return true;
	}
}

