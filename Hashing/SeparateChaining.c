/**
 * Separate chaining:
 *                           / α + e^-α (ASLu and insertion)
 * p (i.e. Expected value) = 
 *                           \ 1 + α/2 (ASLs)
 */
#define KEYLENGTH 15	/* The maximum length of the keyword string */
typedef char ElementType[KEYLENGTH+1];
typedef int Index;	/* The address type of hash */

/******** Definition of single list ********/
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/******** Definition of single list ********/

typedef struct TblNode *HashTable;
struct TblNode {
	int TableSize;
	List Heads;
};

HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;

	H = (HashTable) malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);

	/* List head array */
	H->Heads = (List) malloc(H->TableSize * sizeof(struct LNode));
	for (i = 0; i < H->TableSize; i++) {	/* Initialize the head nodes */
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].Next = NULL;
	}
	return H;
}

Position Find(HashTable H, ElementType Key)
{
	Position P;
	Index Pos;

	Pos = Hash(Key, H->TableSize);	/* The initial hash position */
	P = H->Heads[Pos].Next;		/* Start from the first node of current list */
	while (P && strcmp(P->Data, Key))
		P = P->Next;	/* Have not reached the end and find the Key yet */ 

	return P; 	/* P points to the spotted node or NULL */
}

bool Insert(HashTable H, ElementType Key)
{
	Position P, NewCell;
	Index Pos;

	P = Find(H, Key);
	if (!P) { 	/* Couldn't find the Key, insert it */
		NewCell = (Position) malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		Pos = Hash(Key, H->TableSize); 	/* Initial hash position */
		/* Insert NewCell as the first node of H->Heads[Pos] list */
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell; 
		return true;
	} else {
		printf("The Key already exists!\n");
		return false;
	}
}

void DestroyTable(HashTable H)
{
	int i;
	Position P, Tmp;

	for (i = 0; i < H->TableSize; i++) {	/* Free every node of every list */
		P = H->Heads[i].Next;
		while (P) {
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->Heads);		/* Free the array of head nodes */
	free(H); 	/* Free hash node */
}

