/**
 * Create binary tree with pre&in sequence of tree 
 */
#include <cstdio>
#include <queue>
using namespace std;

#define Max_L 100

typedef struct BNode *BinTree;
struct BNode {
	int data;
	int level;
	BinTree left, right;
};

BinTree CreatBT(int pre[], int in[], int preL, int preR, int inL, int inR)
{
	if (preL > preR) return NULL; 	// length is less than 0
	
	BinTree newNode = new BNode;
	newNode->data = pre[preL];
	int k;
	for (k = inL; k <= inR; k++)
		if (in[k] == pre[preL]) break;
	
	int numLeft = k - inL;
	newNode->left = CreatBT(pre, in, preL+1, preL+numLeft, inL, k-1);
	newNode->right = CreatBT(pre, in, preL+numLeft+1, preR, k+1, inR);
	
	return newNode;
}

void levelOrder(BinTree T)
{
	if (T == NULL)
		return ;
	queue<BinTree> Q;
	T->level = 1;
	Q.push(T);
	while (!Q.empty()) {
		BinTree tmp = Q.front();
		Q.pop();
		printf(" %d", tmp->data);
		if (tmp->left) {
			tmp->left->level = tmp->level+1;
			Q.push(tmp->left);
		}
		if (tmp->right) {
			tmp->right->level = tmp->level+1;
			Q.push(tmp->right);
		}
	}
}

void postOrder(BinTree T)
{
	if (T == NULL)
		return ;
	postOrder(T->left);
	postOrder(T->right);
	printf(" %d", T->data);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int pre[Max_L], in[Max_L], N;

	// 6
	// 1 2 5 3 6 7
	// 2 5 1 6 3 7
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", pre+i);
	for (int i = 0; i < N; i++)
		scanf("%d", in+i);
	BinTree root = CreatBT(pre, in, 0, N-1, 0, N-1);
	printf("level:");
	levelOrder(root);
	printf("\n");
	
	printf("post:");
	postOrder(root);
	printf("\n");

	return 0;
}

