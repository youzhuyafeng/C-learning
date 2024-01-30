#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXARC 10
#define MAXNODE 10
#define DataType int


typedef struct MyGragh {
	int vertexNum;
	int arcNum;
	int arc[MAXARC][MAXARC];
	DataType vertex[MAXARC];
}MyGragh;

typedef struct ArcList {
	int mark;
	struct ArcList* next;

}ArcList;

typedef struct GraghLink {
	DataType vertex;
	ArcList* link;
}GraghLink;

typedef struct GraghLinkList {
	GraghLink gl[MAXNODE];
	int vertexNUM;
	int arcNum;
}GraghLinkList;

void initGragh(MyGragh* g, DataType v[], int an, int vn) {
	g->arcNum = an;
	g->vertexNum = vn;
	for (int i = 0; i < vn; i++) {
		g->vertex[i] = v[i];
	}
	for (int i = 0; i < vn; i++) {
		for (int j = 0; j < vn; j++) {
			g->arc[i][j] = 0;
		}
	}
}

void SetArc(MyGragh* g) {
	for (int i = 0; i < g->arcNum; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		g->arc[v1][v2] = 1;
		g->arc[v2][v1] = 1;
	}
}

bool isLink(MyGragh*g,int v1, int v2) {
	if (g->arc[v1][v2]) {
		return true;
	}
	return false;
}


void initGragh_LinkList(GraghLinkList* gll,DataType v[],int vn,int an) {
	gll->arcNum = an;
	gll->vertexNUM = vn;
	for (int i = 0; i < vn; i++) {
		gll->gl[i].link = NULL;
		gll->gl[i].vertex = v[i];
	}
}

void Set_LinkList_Arc(GraghLinkList*gll) {
	for (int i = 0; i < gll->arcNum; i++) {
		int a1,a2;
		scanf("%d%d", &a1, &a2);
		ArcList* newarc = (ArcList*)malloc(sizeof(ArcList));
		if (newarc == NULL) {
			return;
		}
		newarc->next = gll->gl[a1].link;
		newarc->mark = a2;
		gll->gl[a1].link = newarc;
	}
}

void print(MyGragh* g,int node) {
	printf("%d ",g->vertex[node]);
}

void DFS(MyGragh* g,int node) {
	static visit[MAXNODE] = {0};
	print(g, node);
	visit[node] = 1;
	for (int i = 0; i < g->vertexNum; i++) {
		if (g->arc[node][i]&&(!visit[i])) {
			DFS(g, i);
		}
	}
}
int main(void) {

	MyGragh g;
	int v[8] = { 1,2,3,4,5,6,7,8 };
	initGragh(&g, v, 9, 8);
	SetArc(&g);
	DFS(&g, 0);
	return 0;
}
