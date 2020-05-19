// counting sort: T=O(k+n), linear when k is small

// eg: A = 4, 1, 3, 4, 3  (all in the range of 1-4)
//     C = 1, 0, 2, 2
//     C'= 1, 1, 3, 5     (running totals)
//     B = 1, 3, 3, 4, 4  (result)
countingSort() {
	for i <- 1 to k
		do C[i] <- 0
	for j <- 1 to n
		do C[A[j]] <- C[A[j]]+1  // C[i] = |{key=i}|
	for i <- 2 to k
		do C[i] <- C[i] + C[i-1] // C[i] = |{key<=i}|
	for j <- n downto 1
		do B[C[A[j]]] <- A[j]
			C[A[j]] <- C[A[j]]-1
}
