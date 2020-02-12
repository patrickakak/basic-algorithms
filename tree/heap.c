/**
 * IMPLEMENTATION OF Heap
 */
typedef int ElementType;
typedef struct HeapStruct *Heap;
struct HeapStruct {
	ElementType *Elements;
	int Size, Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
#define MaxData 10000
#define ERROR -1
MaxHeap Create(int MaxSize) {
	MaxHeap H = (MaxHeap) malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType *) malloc((MaxSize+1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;
	return H;
}
// Insert item into MaxHeap, H->Elements[0] has been set
bool Insert(MaxHeap H, ElementType item) {
	if (IsFull(H)) {
		printf("MaxHeap is full!\n");
		return false;
	}
	int p = ++H->Size;
	H->Elements[p] = item;
	PercolateUp(p, H);
	return true;
}
bool IsFull(MaxHeap H) {
	return H->Size == H->Capacity;
}
ElementType DeleteMax(MaxHeap H) {
	if (IsEmpty(H)) {
		printf("MaxHeap is empty!\n");
		return ERROR;
	}
	ElementType MaxItem = H->Elements[1];
	H->Elements[1] = H->Elements[H->Size--];
	PercolateDown(1, H);
	return MaxItem;
}
bool IsEmpty(MaxHeap H) {
	return H->Size == 0;
}
/* We can get T = O(N) rather by using Insert function to get T = O(NlogN)
 * Prerequisite: Knowing the number of input beforehand 
 */
MaxHeap BuildHeap(int N) {
	MaxHeap H = Create(N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &H->Elements[i]);
		H->Size++;
	}
	for (int i = N/2; i > 0; i--)
		PercolateDown(i, H);
	return H;
}
void PercolateUp(int p, MaxHeap H) {
	int i = p;
	ElementType Tmp = H->Elements[p];
	for ( ; H->Elements[i/2] < Tmp; i /= 2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = Tmp;
}
void PercolateDown(int p, MaxHeap H) {
	ElementType Tmp = H->Elements[p];
	int Parent, Child;
	for (Parent = p; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if (Child != H->Size && H->Elements[Child] < H->Elements[Child+1])
			Child++;	/* Child point to the larger one of two children */
		if (Tmp >= H->Elements[Child]) break;
		else H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = Tmp;
}
