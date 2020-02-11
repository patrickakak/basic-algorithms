typedef struct LNode *List;
struct LNode {
	ElementType Element[MAXSIZE];
	int Length;
};
int SequentialSearch(List Tbl, int K) {
	Tbl->Element[0] = K:
	int i;
	for (i = Tbl->Length; Tbl->Element[i] != K; i--) ;
	return i;
}
int SequentialSearch(List Tbl, int K) {
	int i;
	for (i = Tbl->Length; i > 0 && Tbl->Element[i] != K; i--) ;
	return i;
}
