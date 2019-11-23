/**
 * Static implementation of normal tree
 */
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define maxn 100010
struct Node {
	int data, level;
	vector<int> child;
} node[maxn];
int index = 0;

int newNode(int v)
{
	node[index].data = v;
	node[index].child.clear();
	return index++;
}

// Preorder or tree resembles the process of DFS
void PreOrder(int root)
{
	printf("%d ", node[root].data);
	for (int i = 0; i < (int)node[root].child.size(); i++)
		PreOrder(node[root].child[i]);
}

// Levelorder of tree resembles the process of BFS
void LevelOrder(int root)
{
	queue<int> Q;
	Q.push(root);
	node[root].level = 0;
	while (!Q.empty()) {
		int front = Q.front();
		printf("%d ", node[front].data);
		Q.pop();
		for (int i = 0; i < (int)node[front].child.size(); i++) {
			int child = node[front].child[i];
			node[child].level = node[front].level + 1;
			Q.push(child);
		}
	}
}

