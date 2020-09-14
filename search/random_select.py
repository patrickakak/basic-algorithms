def RANDOMIZED_SELECT(A, p, r, i):
	if p == r:
		return A[p]
	q = RANDOMIZED_PARTITION(A, p, r)
	k = q - p + 1
	if i == k:
		return A[q]
	elif i < k:
		return RANDOMIZED_SELECT(A, p, q-1, i)
	else:
		return RANDOMIZED_SELECT(A, q+1, r, i-k)
