
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 10000;
int Partition(int A[], int left, int right)
{
	int tmp = A[left];
	while (left < right) {
		while (left < right && A[right] > tmp) right--;
		A[left] = A[right];
		while (left < right && A[left] <= tmp) left++;
		A[right] = A[left];
	}
	A[left] = tmp;
	return left;
}

void quickSort(int A[], int left, int right)
{
	if (left < right) {
		int pos = Partition(A, left, right);
		quickSort(A, left, pos-1);
		quickSort(A, pos+1, right);
	}
}

void QSort(int A[], int n)
{
	quickSort(A, 0, n-1);
}

int main()
{
	int A[maxn] = {8,6,12,94,0,4,5};
	QSort(A, 7);
	for (int i = 0; i < 7; i++) {
		cout << A[i] << " ";
	}
	return 0;
}

