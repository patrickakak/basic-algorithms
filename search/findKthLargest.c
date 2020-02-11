ElementType FindKthLargest(ElementType S[], int K, int Left, int Right) {
	ElementType e = S[Left];
	int L = Left, R = Right;
	while (1) {
		while ((Left <= Right) && (e <= S[Left])) Left++;
		while ((Left < Right) && (e > S[Right])) Right--;
		if (Left < Right) swap(S[Left], S[Right]);
		else break;
	}
	swap(S[Left-1], S[L]);
	if (Left-L-1 >= K) return FindKthLargest(S, K, L, Left-2);
	else if (Left-L-1 == K-1) return e;
	else return FindKthLargest(S, K-(Left-L-1)-1, Left, R);
}
ElementType Median(ElementType S[], int N) {
	return FindKthLargest(S, (N+1)/2, 0, N-1);
}
