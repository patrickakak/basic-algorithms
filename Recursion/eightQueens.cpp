/**
 * Backtracking method: 8 quenes problem
 */
#include <cstdio>
#include <cmath>
#include <cstdlib>

#define n 8
#define maxn 100
bool hashTbl[maxn] = {false};
int P[maxn], count = 0;
void generateP(int index)
{
	if (index == n+1) {
		count++;
		return;
	}
	for (int x = 1; x <= n; x++)
		if (hashTbl[x] == false) {
			bool flag = true;
			for (int pre = 1; pre < index; pre++)
				if (abs(index - pre) == abs(x - P[pre])) {
					flag = false;
					break;
				}
			if (flag) {
				P[index] = x;
				hashTbl[x] = true;
				generateP(index + 1);
				hashTbl[x] = false;
			}
		}
}

int main()
{
	generateP(1);

	printf("count=%d", count);
	return 0;
}


