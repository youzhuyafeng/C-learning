#if 0
#define _CRT_SECURE_NO_WARNINGS
#define MAXARC 10
#define MAXNODE 10
#define DataType int 
#include <stdio.h>

//最小生成树Kruskal克鲁斯卡尔算法，是针对线进行的最小生成树算法。
//Kruskal算法首先对所有线进行排序，无论是邻接矩阵还是邻接表其排序算法时间复杂度都不低，因此采用全新存储结构
//在数据输入时就排好序，设计一个结构体，from，to,weight成员。
//循环结构体数组，从小权到大权，判定是否构成环，直到线的数量为节点数N-1结束，即最小生成树。
//难点在于如何判断环。采用parent数组的方式，如果选定的两个点位于同一颗树上（抽象为相同根节点），就会成环。

int parent[MAXNODE] = { 0 };
typedef struct Arc {
	int from,to;
	int weight;
}Arc;

typedef struct OrderGragh {
	int ArcNum,vertexNum;
	DataType vertex[MAXNODE];
	Arc ArcList[MAXARC];
}OrderGragh;


void initOrderGragh(OrderGragh* og, DataType v[], int an, int vn) {
	og->ArcNum = an;
	og->vertexNum = vn;
	for (int i = 0; i < og->vertexNum; i++) {
		og->vertex[i] = v[i];
	}
	int from, to, weight;
	for (int i = 0; i < og->ArcNum; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		og->ArcList[i].from = from;
		og->ArcList[i].to = to;
		og->ArcList[i].weight = weight;
	}
}

void initparent(int parent[],int vn) {
	for (int i = 0; i < vn; i++) {
		parent[i] = -1;
	}
}

int findParent(int child) {
	while(parent[child] != -1) {
		child = parent[child];
	}
	return child;
}
int KrusKal(OrderGragh*og,int start) {
	int sigma = 0;
	int count = 0;
	for (int i = 0; i < og->ArcNum; i++) {
		int Node1 = findParent(og->ArcList[i].from);
		int Node2 = findParent(og->ArcList[i].to);
		if (Node1 != Node2) {
			parent[Node1] = Node2;
			sigma += (og->ArcList[i].weight);
			count++;
		}
		if (count == og->vertexNum - 1) {
			break;
		}
	}
	return sigma;
}

int main(void) {
	int vertex[6] = { 0,1,2,3,4,5 };
	initparent(parent, 6);
	OrderGragh og;
	initOrderGragh(&og, vertex, 9, 6);
	int sigma = KrusKal(&og, 0);
	printf("%d",sigma);
	return 0;
}
#endif