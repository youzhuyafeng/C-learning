#define _CRT_SECURE_NO_WARNINGS
#define Datatype char
#include <stdio.h>
#include <stdbool.h>


//二叉线索树数据元素结构体
typedef struct BiClueTree {
	int ltag;
	struct BiClueTree* lchild;
	Datatype data;
	struct BiClueTree* rchild;
	int rtag;
}BiClueTree;

//根据前序遍历建立二叉树（中序和后序很难建树，第一个必定是#，而且没法“递”）
//ltag、rtag = 1即有子树，=0则无子树
BiClueTree* initBiTree(BiClueTree*bt) {
	Datatype ch = getchar();
	if (ch == '#') {
		bt = NULL;
	}
	else {
		bt = (BiClueTree*)malloc(sizeof(BiClueTree));
		bt->data = ch;
		bt->lchild = initBiTree(bt->lchild);
		if (bt->lchild == NULL) {
			bt->ltag = 0;
		}
		else { bt->ltag = 1; }
		bt->rchild = initBiTree(bt->rchild);
		if (bt->rchild == NULL) {
			bt->rtag = 0;
		}
		else { bt->rtag = 1; }
	}
	return bt;
}

void visit(BiClueTree* bt) {
	printf("%c", bt->data);
}




void inThread(BiClueTree* tree) {
	static BiClueTree* pre = NULL;
	if (tree == NULL) {
		return;
	}
	inThread(tree->lchild);
	if (tree->lchild == NULL) {    //前驱节点
		tree->ltag = 1;
		tree->lchild = pre;
	}
	if (tree->rchild == NULL && pre != NULL) {    //后继节点
		tree->rtag = 1;
		tree->rchild = tree;

	}
	pre = tree;                                      
	inThread(tree->rchild);
}


int main(void) {
	//char tree[15] = { '#','F','#','D','#','G','#','B','#','A','#','C','#','E','#' };
	//BiClueTree* bitree;
	//initBiTree(bitree);
	return 0;
}
