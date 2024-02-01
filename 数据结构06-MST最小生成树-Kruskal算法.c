#if 0
#define _CRT_SECURE_NO_WARNINGS
#define MAXARC 10
#define MAXNODE 10
#define DataType int 
#include <stdio.h>

//��С������Kruskal��³˹�����㷨��������߽��е���С�������㷨��
//Kruskal�㷨���ȶ������߽��������������ڽӾ������ڽӱ��������㷨ʱ�临�Ӷȶ����ͣ���˲���ȫ�´洢�ṹ
//����������ʱ���ź������һ���ṹ�壬from��to,weight��Ա��
//ѭ���ṹ�����飬��СȨ����Ȩ���ж��Ƿ񹹳ɻ���ֱ���ߵ�����Ϊ�ڵ���N-1����������С��������
//�ѵ���������жϻ�������parent����ķ�ʽ�����ѡ����������λ��ͬһ�����ϣ�����Ϊ��ͬ���ڵ㣩���ͻ�ɻ���

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