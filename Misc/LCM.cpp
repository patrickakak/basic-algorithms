/**
 * Least Common Multiple
 */
#include <cstdio>

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	int m, n, r;

	scanf("%d%d", &m, &n);
	r = lcm(m, n);
	printf("%d\n", r);

	return 0;
}

