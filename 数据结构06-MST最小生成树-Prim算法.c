#include "DFS.h"
//Minimal Spanning Tree最小生成树的Prim普利姆算法
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
