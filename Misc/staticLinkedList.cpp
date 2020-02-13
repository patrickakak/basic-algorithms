/**
 * Static Lined List (maxn around 10^5)
 */
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100010
struct Node {
	int addr;
	typename data;
	int next;
	typename XXX;
} node[maxn];
int count = 0;
void init() {
	for (int i = 0; i < maxn; i++) node[i].XXX = maxn;
}
void traverse(int begin) {
	int p = begin;
	while (p != -1) {
		node[p].XXX = 1;
		count++;
		p = node[p]->next;
	}
}
bool cmp(Node a, Node b) {
	if (a.XXX != b.XXX) return a.XXX < b.XXX;
	else {
		// sort valid nodes as you want
	}
}
int main() {
	init();
	return 0;
}
