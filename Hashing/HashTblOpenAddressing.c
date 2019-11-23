/**
 * Create a hash table based on open addressing method 
 */
#define MAXTABLESIZE 100000 	/* Maximum hashtable size */
typedef int ElementType;	/* Keyword type */
typedef int Index; 		/* Element type of hash table address */
typedef Index Position;		/* The type of position of data is same as Index */
typedef enum { Legitimate, Empty, Deleted } EntryType; 	/* Cell status type */

typedef struct HashEntry Cell;
struct HashEntry {
	ElementType Data;
	EntryType Info;
};

typedef struct TblNode *HashTable;
struct TblNode {
	int TableSize;	/* The maximum size of table */
	Cell *Cells;	/* The array to store hash ceil */
};

/* Return a prime that is great than or equal to N */
int NextPrime(int N)
{
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

HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;

	H = (HashTable) malloc(sizeof(struct TblNode));
	/* To make sure that the tablesize if a prime */
	H->TableSize = NextPrime(TableSize);
	/* Declaration of a cell array */
	H->Cells = (Cell *) malloc(H->TableSize * sizeof(Cell));
	for (i = 0; i < H->TableSize; i++)
		H->Cells[i].Info = Empty;	/* Initialize cells to empty status */

	return H;
}

