#define _CRT_SECURE_NO_WARNINGS
#include "DFS.h"
#define MAX 32767

//Dijkstra�Ͻ�˹�����㷨��Դ���·��
//������Prim�㷨��Dijkstra�㷨Ҳ�Ѷ��㼯��Ϊ�����֣����㼯S�Ͷ��㼯V-S��
//���㼯U��ʼֻ��start��㣬V-S��ýڵ����ߣ���ʼ��dist[]���飬�ҳ���СȨ��㣬����СȨ������S���ϣ�
//���½ڵ���������߸���dist[]���顣ע���Ѿ��ڶ��㼯U�е�·��������������ˡ����������ٶ��ˡ�
//ѭ���������̣�ֱ�����㼯V-Uû�нڵ㡣

//����׼����S[]���飬���Ƿ�ʽ��Prim�㷨���ƣ�������Ҫ����������
//Dijkstra�㷨��dist[]��path[]��Prim�㷨��node[],LowCost[]�����Ƶġ�
//dist[]�������ʱ��Ҫǰ������ݡ�������LowCostһ��ֱ����0��

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
		//Ѱ����С���۽��
		for (int j = 0; j < mg->vertexNum; j++) {
			if (dist[j] < min && !s[j]) {
				min = mg->arc[minnode][j];
				temp = j;
			}
		}
		minnode = temp;
		//����dist��path����
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
		printf("0�ŵ�%d�ŵ�·��������%d\n", i, dist[i]);
	}
	return 0;
}