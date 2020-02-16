/**
 * Create a hash table based on open addressing method 
 */
#define MAXTABLESIZE 100000
typedef int ElementType;
typedef int Index;
typedef Index Position;
typedef enum { Legitimate, Empty, Deleted } EntryType;
typedef struct HashEntry Cell;
struct HashEntry {
	ElementType Data;
	EntryType Info;
};
typedef struct TblNode *HashTable;
struct TblNode {
	int TableSize;
	Cell *Cells;
};
int NextPrime(int N) {
	int i, p;
	if (N == 2 || N == 1) return 2;
	p = (N%2) ? N : N+1;
	while (1) {
		for (i = 3; i*i <= p; i++)
			if (!(p%i)) break;
		if (i*i > p) break;
		else p += 2;
	}
	return p;
}
HashTable CreateTable(int TableSize) {
	HashTable H = (HashTable) malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Cells = (Cell *) malloc(H->TableSize * sizeof(Cell));
	for (int i = 0; i < H->TableSize; i++)
		H->Cells[i].Info = Empty;
	return H;
}
