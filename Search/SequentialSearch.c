/* Define MAXSIZE here */
typedef struct LNode *List;
struct LNode {
	ElementType Element[MAXSIZE];
	int Length; 	/* Max length equals MAXSIZE-1 */
};

/* With a sentinel
 * If i equals 0, then you find it! */
int SequentialSearch(List Tbl, int K)
{
	int i;
	Tbl->Element[0] = K:
	for (i = Tbl->Length; Tbl->Element[i] != K; i--) ;
	return i;
}

/* Without a sentinel */
int SequentialSearch(List Tbl, int K)
{
	int i;
	for (i = Tbl->Length; i > 0 && Tbl->Element[i] != K; i--) ;
	return i;
}

