/**
 * Radix sort (stable):
 * Worst: Tw = O(P*(N+B)), extra S = O(N+B)
 * least significant digit first 
 */

/* Assume that there are MaxDigit key and the radix is same */
#define MaxDigit 4
#define Radix 10

/* Bucket element node */
typedef struct Node *PtrToNode;
struct Node {
	int key;
	PtrToNode next;
};

/* Bucket head node */
struct HeadNode {
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

/* LSD=1 by default, MSD <= MaxDigit */
int GetDigit(int X, int D)
{
	int d, i;

	for (i = 1; i <= D; i++) {
		d = X % Radix;
		X /= Radix;
	}
	return d;
}

/* Radix sort - least significant digit first */
void LSDRadixSort(ElementType A[], int N)
{
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL; 

	for (i = 0; i < Radix; i++)		/* Init every bucket as an empty list */
		B[i].head = B[i].tail = NULL;
	/* Store the original sequence into lists in reversed order */
	for (i = 0; i < N; i++) {
		tmp = (PtrToNode) malloc(sizeof(struct Node));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	/* Start to sort: process every digit of data in a loop */ 
	for (D = 1; D <= MaxDigit; D++) {
		/* Distribution process */
		p = List;
		while (p) {
			/* Get the current digit of the current element */
			Di = GetDigit(p->key, D);
			tmp = p; p = p->next;	/* Remove from List */
			tmp->next = NULL;	/* Insert into the tail of B[Di] bucket */
			if (B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else {
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}
		/* Collecting process */
		List = NULL; 
		/* Collect elements in every bucket into list in order */
		for (Di = Radix-1; Di >= 0; Di--)
			if (B[Di].head) {	/* If the bucket is not empty */
				/* Insert the whole bucket into the head of List */
				B[Di].tail->next = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL;		/* Empty the bucket */
			}
	}
	/* Move elements from List to A[] and free memory */
	for (i = 0; i < N; i++) {
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		free(tmp);
	} 
}

