#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXNUM 32767
typedef struct HaffmanTree {
	int weight;
	int parent, lchild, rchild;
}HfTree;

//两个最小值算法
void FindLeast(HfTree ht[], int k, int* i1, int* i2) {
	int min1 = MAXNUM; int lnode = -1;
	int min2 = MAXNUM; int rnode = -1;
	for (int i = 0; i < k; i++) {
		if (ht[i].weight < min1 && ht[i].parent == -1) {
			min2 = min1; rnode = lnode;
			min1 = ht[i].weight; lnode = i;
		}
		else if (ht[i].weight < min2 && ht[i].parent == -1) {
			min2 = ht[i].weight; rnode = i;
		}
	}
	*i1 = lnode;
	*i2 = rnode;

}


void BuildHfTree(HfTree ht[], int w[], int account) {
	//初始化哈夫曼树结构体数组
	for (int i = 0; i < 2 * account - 1; i++) {
		if (i < account) {
			ht[i].weight = w[i];
		}
		ht[i].lchild = -1;
		ht[i].rchild = -1;
		ht[i].parent = -1;
	}
	for (int k = account; k < 2 * account - 1; k++) {
		int i1,i2;
		FindLeast(ht, k, &i1, &i2);
		ht[k].weight = ht[i1].weight + ht[i2].weight;
		ht[k].lchild = i1;
		ht[k].rchild = i2;
		ht[i1].parent = k;
		ht[i2].parent = k;
	}
}

void HaffmanCoding(HfTree ht[], char** HaffCode,int account) {
	char* temp = (char*)malloc(account);
	if (!temp) {
		return;
	}
	temp[account-1] = '\0';
	for (int i = 0; i < account; i++) {
		int start = account - 2;
		int pos = i;
		int father = ht[i].parent;
		while (father!=-1) {
			if (ht[father].lchild == pos) 
				temp[start] = '0';
			else 
				temp[start] = '1';
			start--;
			pos = father;
			father = ht[father].parent;
		}
		strcpy(HaffCode[i], &(temp[start + 1]));
		
	}
	free(temp);
}

void HaffCodeSpace(char** HaffCode,int account) {
	for (int i = 0; i < account; i++) {
		HaffCode[i] = (char*)malloc(10);
	}
}

int main(void) {
	int w[10] = { 3,6,4,19,7,21,13,1,9,24 };
	HfTree ht[19];
	char* HaffCode[10];
	HaffCodeSpace(HaffCode, 10);
	BuildHfTree(ht,w,10);

	HaffmanCoding(ht, HaffCode, 10);
	for (int i = 0; i < 10; i++) {
		printf("%s\n", HaffCode[i]);
	}
	return 0;
	
}