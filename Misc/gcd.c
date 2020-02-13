/**
 * Greatest Common Divisor
 * (Euclidean algorithm)
 */
#include <stdio.h>
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
int main() {
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
		printf("%d\n", gcd(m, n));
	return 0;
}
