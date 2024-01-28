#define _CRT_SECURE_NO_WARNINGS
#define Datatype char
#include <stdio.h>
#include <stdbool.h>


//��������������Ԫ�ؽṹ��
typedef struct BiClueTree {
	int ltag;
	struct BiClueTree* lchild;
	Datatype data;
	struct BiClueTree* rchild;
	int rtag;
}BiClueTree;

//����ǰ���������������������ͺ�����ѽ�������һ���ض���#������û�����ݡ���
//ltag��rtag = 1����������=0��������
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
	if (tree->lchild == NULL) {    //ǰ���ڵ�
		tree->ltag = 1;
		tree->lchild = pre;
	}
	if (tree->rchild == NULL && pre != NULL) {    //��̽ڵ�
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
