/**
 * Static Lined List (maxn around 10^5)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100010
struct Node {
	int addr;		// address
	typename data;
	int next;		// NULL: -1 to end
	typename XXX;	// property/flag
} node[maxn];
int count = 0;		// # of valid nodes

void init()
{
	for (int i = 0; i < maxn; i++)
		node[i].XXX = maxn; 	// set all nodes invalid (to sort() later)
}

void traverse(int begin)
{
	int p = begin;
	while (p != -1) {
		node[p].XXX = 1;
		count++;
		p = node[p]->next;
	}
}

bool cmp(Node a, Node b)
{
	if (a.XXX != b.XXX)		// degrade invalid nodes
		return a.XXX < b.XXX;
	else {
		// sort valid nodes as you want
	}
}

int main()
{
	init();

	return 0;
}


