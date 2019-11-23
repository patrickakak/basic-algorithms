/**
 * Binary Indexed Tree (aka Fenwick tree)
 *
 * (the most classic use of BIT is to calculate # of elements 
 * less than the current element)
 */
#include <cstdio>
#include <cstring>

const int maxn = 100010;
#define lowbit(i) ((i)&(-i))
int c[maxn];

void update(int x, int v)
{
	for (int i = x; i < maxn; i += lowbit(i))
		c[i] += v;
}

int getSum(int x)
{
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		sum += c[i];
	return sum;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, x;

	/**
	 *  _________________________________________
	 * |                                1000 C[8]| lowbit(8)=8
	 * |_________________________________________|
	 *  _________________                    |
	 * |        0100 C[4]|                   |     lowbit(4)=4
	 * |_________________|                   |
	 *  __________      |   __________       |
	 * | 0010 C[2]|     |  | 0110 C[6]|      |     lowbit(2)=2, lowbit(6)=2
	 * |__________|     |  |__________|      |
	 *  ____   |  ____  |   ____   |   ____  |
	 * |C[1]|  | |C[3]| |  |C[5]|  |  |C[7]| |     lowbit(1)=1, lowbit(3)=1
	 * |____|  | |____| |  |____|  |  |____| |     lowbit(5)=1, lowbit(7)=1
	 *  __|____|____|___|____|_____|____|____|___
	 * |  1    2    3    4    5    6    7    8   |
	 * -------------------------------------------
	 */
	scanf("%d", &n);
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		update(x, 1);
		printf("%d\n", getSum(x-1));
	}

	return 0;
}


