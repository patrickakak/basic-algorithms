/**
 * Separate chaining:
 *                           / α + e^-α (ASLu and insertion)
 * p (i.e. Expected value) = 
 *                           \ 1 + α/2 (ASLs)
 */
#define KEYLENGTH 15
typedef char ElementType[KEYLENGTH+1];
typedef int Index;
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
typedef struct TblNode *HashTable;
struct TblNode {
	int TableSize;
	List Heads;
};
HashTable CreateTable(int TableSize) {
	HashTable H;
	int i;
	H = (HashTable) malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Heads = (List) malloc(H->TableSize * sizeof(struct LNode));
	for (i = 0; i < H->TableSize; i++) {
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].Next = NULL;
	}
	return H;
}
Position Find(HashTable H, ElementType Key) {
	Position P;
	Index Pos;
	Pos = Hash(Key, H->TableSize);
	P = H->Heads[Pos].Next;
	while (P && strcmp(P->Data, Key))
		P = P->Next;
	return P;
}
bool Insert(HashTable H, ElementType Key) {
	Position P, NewCell;
	Index Pos;
	P = Find(H, Key);
	if (!P) {
		NewCell = (Position) malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		Pos = Hash(Key, H->TableSize);
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell; 
		return true;
	} else {
		printf("The Key already exists!\n");
		return false;
	}
}
void DestroyTable(HashTable H) {
	int i;
	Position P, Tmp;
	for (i = 0; i < H->TableSize; i++) {
		P = H->Heads[i].Next;
		while (P) {
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->Heads);
	free(H);
}
