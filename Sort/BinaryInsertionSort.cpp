/**
 * Binary insertion sort: T=O(n^2)
 *
 * improve insertion sort by finding the position to insert more effeciently
 */

int findPlace(ElementType A[], ElementType tmp, int high)
{
	int mid, low = 0;

	while (low <= high) {
		mid = (low + high)/2;
		if (tmp >= A[mid])	/* Add '=' in order to move less elements */
			low = mid + 1;
		else
			high = mid - 1;
	}
	return high+1;
}

void BinaryInsertionSort(ElementType A[], int N)
{
	int i, j, high, p;
	ElementType tmp;

	for (high=0, i=1; i < N; i++) {
		tmp = A[i];
		p = findPlace(A, tmp, high);
		for (j = high; j >= p; j--)
			A[j+1] = A[j];
		A[p] = tmp;
		high += 1;
	}
}

