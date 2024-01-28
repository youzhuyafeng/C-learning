#define _CRT_SECURE_NO_WARNINGS
#define MAX 400
#define length 8
#define width 8
#include <stdio.h>
#include <stdbool.h>

#if 0
//方向数组，分别为上左下右
int direct[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
typedef struct Stack {
	int* xtop;
	int* ytop;
	int* xarr;		//x坐标栈
	int* yarr;      //y坐标栈
}Stack,*Pstack;

void initStack(Pstack s) {
	s->xarr = (int*)malloc(MAX);
	s->yarr = (int*)malloc(MAX);	if ((s->xarr == NULL) || (s->yarr == NULL)) {
		return;
	}
	s->xtop = s->xarr;
	s->ytop = s->yarr;
	*(s->xtop) = 0;
	*(s->ytop) = 0;
}	

void destroyStack(Pstack s) {
	free(s->xarr);
	free(s->yarr);
	s->xarr = NULL;
	s->yarr = NULL;
}

void Push(Pstack s, int x) {
	*(s->xtop + 1) = *(s->xtop) + direct[x][0];
	*(s->ytop + 1) = *(s->ytop) + direct[x][1];
	s->xtop++;
	s->ytop++;
}


void Pop(Pstack s) {
	s->xtop--;
	s->ytop--;
}

bool FindTop(Pstack s) {
	if (*(s->xtop) + *(s->ytop) == width+length-2)
		return true;
	else
		return false;
}

int mezi[length + 2][width + 2] = { {1,1,1,1,1,1,1,1,1,1},
									{1,1,0,1,0,0,0,1,0,1},
									{1,0,0,1,0,0,0,1,0,1},
									{1,0,0,0,0,1,1,0,0,1},
									{1,0,1,1,1,0,0,0,0,1},
									{1,0,0,0,1,0,0,0,0,1},
									{1,0,1,0,0,0,1,0,0,1},
									{1,0,1,1,1,0,1,1,0,1},
									{1,1,0,0,0,0,0,0,0,1},
									{1,1,1,1,1,1,1,1,1,1}

};


bool FindRoad(Pstack s, int x) {
	int p = *(s->xtop) + direct[x][0]+1;
	int q = *(s->ytop) + direct[x][1]+1;
	if (mezi[p][q] == 2 || mezi[p][q] == 1) {
		return false;
	}
	else {
		return true;
	}
}

void SetOne(Pstack s) {
	int p = *(s->xtop)+1;
	int q = *(s->ytop)+1;
	mezi[p][q] = 2;
}
	
int main(void) {

	Stack s;
	Pstack ps = &s;
	initStack(ps);
	int i;
	int count = 0;
	int j;
	while (1) {
		i = 0;
		while (i < 4) {
			if (FindRoad(ps, i)) {
				Push(ps, i);
				SetOne(ps);
				count++;
				break;
			}
			else {
				i++;
				continue;
			}
		}
		if (FindTop(ps)){
			break;
		}
		if (i == 4) {
			Pop(ps);
			count--;
			continue;
		}
	}
	for (j = 0; j < count; j++) {

		printf("(%d,%d)",*(ps->xarr+j),*(ps->yarr+j));
	}
	destroyStack(ps);
	printf("找到了！");
	return 0;
}
#endif