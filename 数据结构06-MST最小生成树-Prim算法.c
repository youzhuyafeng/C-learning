#if 0
#include "DFS.h"
//Minimal Spanning Tree��С��������Prim����ķ�㷨
//Prim�㷨�ص��ǶԵ���в�������ͼ�ĵ㼯V��Ϊ�������ϣ�����������U���ѡ�ڵ㼯��V-U��
//�㷨��ʼʱ������U��ֻ��һ����ʼ�㣬����V-U�㼯�ϵ�ÿһ�㶼�Լ���U����ʼ�����ߣ���Ϊ��ѡ�������顣
//���������У�V-U�д��ۣ�cost����С�����ߵ㽫��ΪU���ϵ��³�Ա��
//�㼯V-U���³�Ա�������ߣ����º�ѡ�������飬�ظ��������̣�ֱ�����е㶼�ڼ���U�С�

//���㷨�ѵ��������ȷ������U�ͼ���V-U����ƽṹ��shortEdge��node����С����Ŀ��㣨���㼯U�г�Ա��
//LowCost��0����V-U�г�Ա�������ߡ����ǽ�V-U�����еĵ�LowCost��0��
#define MAX 32767

//��СȨ��ѡ�ṹ������
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
		//���޸ĵĺ�ѡ����������ҵ���С���۽�㡣
		for (int j = 0; j < size; j++) {
			if (se[j].LowCost && se[j].LowCost < Min) {
				MinNode = j;
				Min = se[j].LowCost;
			}
		}
		se[MinNode].LowCost = 0;
		//�¼��뼯��U�Ľڵ��޸ĺ�ѡ��
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