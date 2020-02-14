/**
 * Radix sort (stable):
 * Worst: Tw = O(P*(N+B)), extra S = O(N+B)
 * (N: # of unsorted elements,  B: # of buckets)
 * Most significant digit first 
 */
#define MaxDigit 4
#define Radix 10
typedef struct Node *PtrToNode;
struct Node{
	int key;
	PtrToNode next;
};
struct HeadNode {
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];
int GetDigit(int X, int D) {
	int d, i;
	for (i = 1; i <= D; i++) {
		d = X % Radix;
		X /= Radix;
	}
	return d;
}
void MSD(ElementType A[], int L, int R, int D) {
	int Di, i, j;
	Bucket B;
	PtrToNode tmp, p, List = NULL;
	if (D == 0) return;
	for (i = 0; i < Radix; i++)
		B[i].head = B[i].tail = NULL;
	for (i = L; i <= R; i++) {
		tmp = (PtrToNode) malloc(sizeof(struct Node));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	p = List;
	while (p) {
		Di = GetDigit(p->key, D);
		tmp = p; p = p->next;
		if (B[Di].head == NULL)
			B[Di].tail = tmp;
		tmp->next = B[Di].head;
		B[Di].head = tmp;
	}
	i = j = L;
	for (Di = 0; Di < Radix; Di++)
		if (B[Di].head) {
			p = B[Di].head;
			while (p) {
				tmp = p;
				p = p->next;
				A[j++] = tmp->key;
				free(tmp);
			}
			MSD(A, i, j-1, D-1);
			i = j;
		} 
}
void MSDRadixSort(ElementType A[], int N) {
	MSD(A, 0, N-1, MaxDigit); 
}
