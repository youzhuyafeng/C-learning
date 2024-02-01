#if 0
#include "DFS.h"
//Minimal Spanning Tree最小生成树的Prim普利姆算法
//Prim算法重点是对点进行操作，将图的点集V分为两个集合，生成树集合U与候选节点集合V-U。
//算法开始时，集合U中只有一个起始点，其中V-U点集合的每一点都对集合U中起始点连线，称为候选连线数组。
//连线数组中，V-U中代价（cost）最小的连线点将成为U集合的新成员。
//点集V-U与新成员进行连线，更新候选连线数组，重复上述过程，直到所有点都在集合U中。

//该算法难点在于如何确定集合U和集合V-U。设计结构体shortEdge，node作最小连线目标点（即点集U中成员）
//LowCost非0即是V-U中成员。“连线”就是将V-U集合中的点LowCost置0。
#define MAX 32767

//最小权候选结构体数组
typedef struct shortEdge {
	int node;
	int LowCost;
}shortEdge;

shortEdge se[MAXNODE] = { 0 };

void initShortEdge(MyGragh* mg, int size, int start) {
	for (int i = 0; i < size; i++) {
		se[i].LowCost = mg->arc[start][i];
		se[i].node = start;
	}
}
//size 6 start 0
int Prim(MyGragh* mg,int size,int start ) {
	initShortEdge(mg, size, start);
	int add=0;
	int Min;
	int MinNode;
	for (int i = 0; i < size - 1; i++) {
		Min = MAX;
		//对修改的候选表进行排序，找到最小代价结点。
		for (int j = 0; j < size; j++) {
			if (se[j].LowCost && se[j].LowCost < Min) {
				MinNode = j;
				Min = se[j].LowCost;
			}
		}
		se[MinNode].LowCost = 0;
		//新加入集合U的节点修改候选表
		for (int j = 0; j < size; j++) {
			if ((mg->arc[MinNode][j] < se[j].LowCost) && se[j].LowCost) {
				se[j].LowCost = mg->arc[MinNode][j];
				se[j].node = MinNode;
			}
		}
		add += Min;
	}
	return add;
}

int main(void) {
	MyGragh mg;
	int vertex[6] = { 0,1,2,3,4,5 };
	initGragh(&mg,vertex,9,6);
	SetArc(&mg);
	int add = Prim(&mg, 6, 0);
	printf("%d", add);
	return 0;
}
#endif