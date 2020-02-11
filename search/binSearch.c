#define NotFound -1
typedef struct Node *List;
struct Node {
	ElementType Data[MaxSize];
	int Length;
};
int BinarySearch(List Tbl, ElementType K) {
	int left = 1, right = Tbl->Length, mid;
	while (left <= right) {
		mid = left + (right-left)/2;
		if (K < Tbl->Data[mid]) right = mid - 1;
		else if (K > Tbl->Data[mid]) left = mid + 1;
		else return mid;
	}
	return NotFound;
}
int lower_bound(int A[], int left, int right, int x) {
	while (left < right) {
		int mid = left + (right-left)/2;
		if (A[mid] >= x) right = mid;
		else left = mid + 1;
	}
	return left;
}
int upper_bound(int A[], int left, int right, int x) {
	while (left < right) {
		int mid = (left + right)/2;
		if (A[mid] > x) right = mid;
		else left = mid + 1;
	}
	return left;
}
int solve(int left, int right) {
	while (left < right) {
		int mid = (left + right)/2;
		if (Condition satisfied) right = mid;
		else left = mid + 1;
	}
	return left;
}
