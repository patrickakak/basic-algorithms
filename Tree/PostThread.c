/**
 * Threaded Binary Tree w/ Post-threading
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 	// Sleep(1000)

typedef struct TBTNode *PtrToTBTNode;
typedef PtrToTBTNode TBTree;
struct TBTNode {
	int data;
	int ltag, rtag;
	TBTree lchild, rchild;
	TBTree parent; 		// Added
};

TBTree CreatBT(int pre[], int in[], int L1, int R1, int L2, int R2);
void postThread(TBTree p, TBTree *pre);
void creatThreadBTree(TBTree r);
TBTree First(TBTree p);
void visit(TBTree p);
void postOrder(TBTree r);

int main()
{
	TBTree root;

	// data set1
	/*
	   int pre[10] = {7,2,6,4,1,3,8,9,10,5};
	   int in[10] = {2,1,3,4,6,8,7,10,5,9};
	   root = CreatBT(pre, in, 0, 9, 0, 9);
	   */

	// data set2
	/*
	   int pre[5] = {1,2,3,5,4};
	   int in[5] = {3,2,5,1,4};
	   root = CreatBT(pre, in, 0, 4, 0, 4);
	   */

	// data set 3
	int pre[5] = {3,1,2,4,5};
	int in[5] = {1,4,2,5,3};
	root = CreatBT(pre, in, 0, 4, 0, 4);

	creatThreadBTree(root);

	postOrder(root);

	return 0;
}

TBTree CreatBT(int pre[], int in[], int L1, int R1, int L2, int R2)
{
	int k;
	if (L1 > R1)
		return NULL;
	else {
		TBTree t = (TBTree) malloc(sizeof(struct TBTNode));
		t->ltag = t->rtag = 0;
		t->lchild = t->rchild = NULL;
		t->parent = NULL; 	// Added
		t->data = pre[L1];
		for (k = L2; k <= R2; ++k)
			if (pre[L1] == in[k]) break;
		t->lchild = CreatBT(pre, in, L1+1, L1+k-L2, L2, k-1);
		t->rchild = CreatBT(pre, in, L1+k-L2+1, R1, k+1, R2);
		return t;
	}
}

void postThread(TBTree p, TBTree *pre)
{
	if (p == NULL) return;
	if (p->lchild) p->lchild->parent = p; 	// Added
	if (p->rchild) p->rchild->parent = p;

	postThread(p->lchild, pre);
	postThread(p->rchild, pre);
	if (p->lchild == NULL) {
		p->lchild = (*pre);
		p->ltag = 1;
	}
	if (*pre != NULL && (*pre)->rchild == NULL) {
		(*pre)->rchild = p;
		(*pre)->rtag = 1;
	}
	(*pre) = p;
}

void creatThreadBTree(TBTree r)
{
	TBTree p = NULL;
	TBTree *pre = &p;

	if (!r) return;

	postThread(r, pre);

	// (*pre)->rchild = NULL; // Comment out
	// (*pre)->rtag = 1;
}

TBTree First(TBTree p)
{
	while (p->lchild)
		p = p->lchild;
	return p;
}

void visit(TBTree p)
{
	printf("%d ", p->data);
}

void postOrder(TBTree r)
{
	PtrToTBTNode p, tmp, t;

	p = First(r);
	while (p != r) {
		while (p->rtag == 1) {
			visit(p);
			p = p->rchild;
		}
		if (p == r)
			break;
		else {
			visit(p);
			tmp = p->parent;
			if (tmp->lchild == p) {
				if (tmp->ltag == 1)
					p = tmp;
				else {
					if (tmp->rtag == 0 && tmp->rchild) {
						t = tmp->rchild;
						while (t->lchild != p)
							t = t->lchild;
						p = t;
					} else
						p = tmp;
				}
			} else
				p = tmp;
		}
	}
	visit(r);
}

