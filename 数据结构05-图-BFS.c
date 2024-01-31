#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DFS.h"
#define MAXSIZE 10


typedef struct Queue {
	int front;
	int end;
	DataType* ptr;
	int size;
}Queue;

void initQueue(Queue* q, int s) {
	q->ptr = (DataType*)malloc(s * (sizeof(DataType)));
	if (q->ptr == NULL) {
		return;
	}
	q->front = 0;
	q->end = 0;
	q->size = s;
}



//只剩一个存储单元时队满
bool isfull(Queue* q) {
	if ((q->end + 1) % (q->size) == q->front) {
		return true;
	}
	return false;
}

bool isfree(Queue* q) {
	if (q->end ==q->front) {
		return true;
	}
	return false;
}

void push(Queue* q, DataType data) {
	if (isfull(q)) {
		return;
	}
	*(q->ptr + q->end) = data;
	q->end = (q->end + 1) % q->size;
}

DataType* pop(Queue* q) {
	if (isfree(q)) {
		return NULL;
	}
	int temp = q->front;
	q->front = (q->front+1)%q->size;
	return q->ptr + temp;
}

void destroyQueue(Queue* q) {
	free(q->ptr);
	q->ptr = NULL;
}

void BFS(Queue* q, MyGragh* g,int visit[],int node) {
	push(q, node);
	print(g, node);
	visit[node] = 1;
	while (!isfree(q)) {
		DataType* front = pop(q);
		for (int i = 0; i < g->vertexNum; i++) {
			if (g->arc[*front][i]&&visit[i]==0) {
				push(q, i);
				print(g, i);
				visit[i] = 1; 
			}
		}
	}
}

int main(void) {
	MyGragh g;
	Queue q;
	initQueue(&q, MAXSIZE);
	int vertex[8] = { 1,2,3,4,5,6,7,8 };
	int visit[8] = { 0 };
	initGragh(&g, vertex, 9, 8);
	SetArc(&g);
	BFS(&q, &g, visit, 0);
	return 0;
}
#endif