#define _CRT_SECURE_NO_WARNINGS
#include "DFS.h"
#define MAX 32767

//Dijkstra迪杰斯特拉算法求单源最短路径
//类似于Prim算法，Dijkstra算法也把顶点集分为两部分，顶点集S和顶点集V-S。
//顶点集U初始只有start结点，V-S与该节点连线，初始化dist[]数组，找出最小权结点，将最小权结点放入S集合，
//从新节点出发，连线更新dist[]数组。注意已经在顶点集U中的路径数据无需更新了——不可能再短了。
//循环上述过程，直到顶点集V-U没有节点。

//数据准备：S[]数组，其标记方式与Prim算法类似，但是需要独立出来。
//Dijkstra算法中dist[]和path[]与Prim算法中node[],LowCost[]是相似的。
//dist[]数组更新时需要前面的数据。不能想LowCost一样直接置0。

//0 0 0 0 1 4 0 2 6 0 3 6 0 4 32767 0 5 32767 0 6 32767 1 0 32767 1 1 0 1 2 1 1 3 32767 1 4 7 1 5 32767 1 6 32767 2 0 32767 2 1 32767 2 2 0 2 3 32767 2 4 6 2 5 4 2 6 32767 3 0 32767 3 1 32767 3 2 2 3 3 0 3 4 32767 3 5 5 3 6 32767 4 0 32767 4 1 32767 4 2 32767 4 3 32767 4 4 0 4 5 32767 4 6 6 5 0 32767 5 1 32767 5 2 32767 5 3 32767 5 4 1 5 5 0 5 6 0 6 0 32767 6 1 32767 6 2 32767 6 3 32767 6 4 32767 6 5 32767 6 6 0
int path[MAXARC];
int dist[MAXARC];
int s[7] = { 1,0,0,0,0,0,0 };

void initPathDist(MyGragh* mg,int start) {
	for (int i = 0; i < mg->vertexNum; i++) {
		path[i] = start;
	}
	for (int i = 0; i < mg->vertexNum; i++) {
		dist[i] = mg->arc[start][i];
	}
}

void Dijkstra(MyGragh* mg) {
	for (int i = 0; i < mg->vertexNum-1; i++) {
		int min = MAX;
		static int minnode = 0;
		int temp;
		//寻找最小代价结点
		for (int j = 0; j < mg->vertexNum; j++) {
			if (dist[j] < min && !s[j]) {
				min = mg->arc[minnode][j];
				temp = j;
			}
		}
		minnode = temp;
		//更新dist和path数组
		for (int j = 0; j < mg->vertexNum; j++) {
			if (mg->arc[minnode][j] + dist[minnode] < dist[j] && !s[j]) {
				dist[j] = mg->arc[minnode][j]+dist[minnode];
				path[j] = minnode;
			}
		}
		s[minnode] = 1;
	}
}

int main(void) {
	MyGragh mg;
	int vertex[7] = { 0,1,2,3,4,5,6 };
	initGragh(&mg, vertex, 12, 7);
	SetArc(&mg);
	initPathDist(&mg, 0);
	Dijkstra(&mg);
	for (int i = 0; i < mg.vertexNum; i++) {
		printf("0号到%d号的路径长度是%d\n", i, dist[i]);
	}
	return 0;
}