/**
 * Fast Exponentiation
 */
#include <cstdio>

typedef long long LL;

// Recursive
LL binaryPow_r(LL a, LL b)
{
	if (b == 0)
		return 1;
	if (b & 1)
		return a * binaryPow_r(a, b-1);
	else {
		LL mul = binaryPow_r(a, b/2);
		return mul * mul;
	}
}

// Iterative
LL binaryPow_it(LL a, LL b)
{
	LL ans = 1;
	while (b > 0) {
		if (b % 2 == 1)
			ans *= a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}


int main()
{
	// freopen("tst.txt", "r", stdin);
	LL ret1 = binaryPow_r(2, 10);
	printf("ret1 = %lld\n", ret1);
    
	LL ret2 = binaryPow_it(2, 9);
	printf("ret2 = %lld\n", ret2);

	return 0;
}

