/**
 * Create binary tree with level&in order sequence
 */
#include <cstdio>
#define Max_L 100
typedef struct BNode *BinTree;
struct BNode {
	int data, level;
	BinTree left, right;
};
BinTree CreatBT(int *level, int *in, int N) {
	if (N <= 0) return NULL;
	BinTree newNode = new BNode;
	newNode->data = level[0];
	for (int pos = 0; pos < N; pos++)
		if (in[pos] == level[0]) break;
	int Lin[Max_L], Rin[Max_L], Llev[Max_L], Rlev[Max_L];
	for (int cnt=0, i=0; i < pos; i++, cnt++) Lin[cnt] = in[i];
	for (int cnt=0, i=pos+1; i < N; i++, cnt++) Rin[cnt] = in[i];
	for (int cnt=0, i=1; i < N; i++)
		for (int j = 0; j < pos; j++)
			if (level[i] == in[j]) Llev[cnt++] = level[i];
	for (int cnt=0, i=1; i < N; i++)
		for (int j = pos+1; j < N; j++)
			if (level[i] == in[j]) Rlev[cnt++] = level[i];
	newNode->left = CreatBT(Llev, Lin, pos);
	newNode->right = CreatBT(Rlev, Rin, N-pos-1);
	return newNode;
}
void preOrder(BinTree T) {
	if (!T) return;
	printf(" %d", T->data);
	preOrder(T->left);
	preOrder(T->right);
}
void postOrder(BinTree T) {
	if (T == NULL) return ;
	postOrder(T->left);
	postOrder(T->right);
	printf(" %d", T->data);
}
int main() {
	// freopen("tst.txt", "r", stdin);
	int level[Max_L], in[Max_L], N;
	// 6
	// 1 2 3 5 6 7
	// 2 5 1 6 3 7
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &level[i]);
	for (int i = 0; i < N; i++) scanf("%d", &in[i]);
	BinTree root = CreatBT(level, in, N);
	printf("pre:");
	preOrder(root);
	printf("\n");
	printf("post:");
	postOrder(root);
	printf("\n");
	return 0;
}
