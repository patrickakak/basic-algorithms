/**
 * IMPLEMENTATION OF Heap
 */

typedef int ElementType;
typedef struct HeapStruct *Heap;	/* Definition of heap */
struct HeapStruct {
	ElementType *Elements; 			/* Array to store elements */
	int Size;						/* Current number of elements in heap */
	int Capacity;					/* Maximum capacity of heap */
};
typedef Heap MaxHeap;
typedef Heap MinHeap;

#define MaxData 10000		/* Should be larger than every possible elements */
#define ERROR -1


/* Main functions: */

/* Create a heap of MaxSize capacity */
MaxHeap Create(int MaxSize)
{
	MaxHeap H = (MaxHeap) malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType *) malloc((MaxSize+1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;	/* Set a sentinel */
	return H;
}

/* Insert item into MaxHeap, H->Elements[0] has been set */
bool Insert(MaxHeap H, ElementType item)
{
	int p;
	if (IsFull(H)) {
		printf("MaxHeap is full!\n");
		return false;
	}
	p = ++H->Size;	/* p point to the last element of the MaxHeap */
	H->Elements[p] = item;
	PercolateUp(p, H);
	return true;
}

bool IsFull(MaxHeap H)
{
	return H->Size == H->Capacity;
}

/* Return the maximum and delete a node */
ElementType DeleteMax(MaxHeap H)
{
	ElementType MaxItem;

	if (IsEmpty(H)) {
		printf("MaxHeap is empty!\n");
		return ERROR;
	}
	MaxItem = H->Elements[1];	/* Get the max value to return */
	H->Elements[1] = H->Elements[H->Size--];
	PercolateDown(1, H);
	return MaxItem;
}

bool IsEmpty(MaxHeap H)
{
	return H->Size == 0;
}

/* We can get T = O(N) rather by using Insert function to get T = O(NlogN)
 * Prerequisite: Knowing the number of input beforehand 
 */
MaxHeap BuildHeap(int N)
{
	int i;
	MaxHeap H;

	H = Create(N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &H->Elements[i]);
		H->Size++;
	}
	/* Build a MaxHeap in this way, in the worst case, the time that we need 
	 * to move elements of Heap equals to the sum of every node heights:
	 *     eg. X = [logN], (full binary tree)
	 *     2^0*X + 2^1*(X-1) + 2^2*(X-2) + ... + 2^(X-1) * (X-(X-1))
	 *   = (2^0 + 2^1 + 2^2 + ... + 2^X-1)*X - (2^1 
	 *                 + 2^2*2 + 2^3*3 + ... + 2^(X-1) * (X-1))
	 *   = 2^(X+1) - X - 2 = 2N - logN - 2 (i.e. T = O(N))
	 */
	for (i = N/2; i > 0; i--)
		PercolateDown(i, H);

	return H;
}

void PercolateUp(int p, MaxHeap H)
{
	int i;
	ElementType Tmp;

	/* If parent node is smaller, drag it down along the path to the root */
	for (i=p, Tmp=H->Elements[p]; H->Elements[i/2] < Tmp; i /= 2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = Tmp;
}

/* Percolate down to re-arrange subheap of H->Elements[p] to be a maxheap */
void PercolateDown(int p, MaxHeap H)
{
	ElementType Tmp = H->Elements[p];
	int Parent, Child;

	/* 'Parent*2 <= H->Size' to find out if there is a left child,
	 * 'Parent=Child' to jump into the larger child's position 
	 */
	for (Parent = p; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if (Child != H->Size && H->Elements[Child] < H->Elements[Child+1])
			Child++;	/* Child point to the larger one of two children */
		if (Tmp >= H->Elements[Child]) break;
		else H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = Tmp;
}

