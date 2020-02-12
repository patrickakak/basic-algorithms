/**
 * Threaded Binary Tree w/ Pre-threading
 */
typedef struct TBTNode *PtrToTBTNode;
typedef PtrToTBTNode TBTree;
struct TBTNode {
	int data;
	int ltag, rtag;
	TBTree lchild, rchild;
};
TBTree CreatBT(int pre[], int in[], int L1, int R1, int L2, int R2) {
	if (L1 > R1) return NULL;
	else {
		TBTree t = (TBTree) malloc(sizeof(struct TBTNode));
		t->ltag = t->rtag = 0;
		t->lchild = t->rchild = NULL;
		t->data = pre[L1];
		for (int k = L2; k <= R2; ++k)
			if (pre[L1] == in[k]) break;
		t->lchild = CreatBT(pre, in, L1+1, L1+k-L2, L2, k-1);
		t->rchild = CreatBT(pre, in, L1+k-L2+1, R1, k+1, R2);
		return t;
	}
}
void preThread(TBTree p, TBTree *pre) {
	if (p == NULL) return;
	if (p->lchild == NULL) {
		p->lchild = (*pre);
		p->ltag = 1;
	}
	if (*pre != NULL && (*pre)->rchild == NULL) {
		(*pre)->rchild = p;
		(*pre)->rtag = 1;
	}
	(*pre) = p;
	if (p->ltag == 0) preThread(p->lchild, pre);
	if (p->rtag == 0) preThread(p->rchild, pre);
}
void creatThreadBTree(TBTree r) {
	TBTree p = NULL;
	TBTree *pre = &p;
	if (!r) return;
	preThread(r, pre);
	(*pre)->rchild = NULL;
	(*pre)->rtag = 1;
}
void visit(TBTree p) {
	printf("%d ", p->data);
}
void preOrder(TBTree root) {
	if (root == NULL) return;
	TBTree p = root;
	while (p != NULL) {
		while (p->ltag == 0) {
			visit(p);
			p = p->lchild;
		}
		visit(p);
		p = p->rchild;
	}
}
int main() {
	int pre[7] = {3, 2, 1, 6, 5, 4, 7};
	int in[7] = {1, 2, 3, 4, 5, 6, 7};
	TBTree root = CreatBT(pre, in, 0, 6, 0, 6);
	creatThreadBTree(root);
	preOrder(root);
	return 0;
}
