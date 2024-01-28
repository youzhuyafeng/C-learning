#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 100
#define DataType int
#include <stdio.h>
#include <stdbool.h>

#if 0
//�ŶӴ��ڡ�������
typedef struct Queue {
	int front;
	int end;
	DataType* ptr;
	int size;
}Queue,*Pqueue;

//�˿͵�״̬
typedef struct Coustomer {
	int numbering;  //��Ԥ�ư���ʱ��˳���
	int ArriveTime;
	int Event;
	int Predict;
	int LeftTime;
}Cou,*Pcou;

//ʱ��ڵ㡪�������¼
typedef struct LinkList {
	Pcou* pcou;
	struct LinkList* pll;
}LinkList,*Pll;

//���г�ʼ��
void initQueue(Pqueue pq, int x) {
	pq->ptr = (DataType*)malloc(x);
	if (!pq->ptr) {
		return;
	}
	pq->size = x;
	pq->front = 0;
	pq->end = 0;
}

void DestroyQueue(Pqueue pq) {
	free(pq->ptr);
	pq->ptr = NULL;
}

bool inQueue(Pqueue pq,DataType x) {
	if (isFull(pq) ){
		return false;
	}
	*(pq->ptr + pq->end) = x;
	pq->end = (pq->end+1)%(pq->size);
	return true;
}

bool outQueue(Pqueue pq) {
	if (isFree(pq)) {
		return false;
	}
	pq->front = (pq->front+1)%(pq->size);
	return true;
}

bool isFull(Pqueue pq) {
	if ((pq->end + 1) % (pq->size) == pq->front) {
		return true;
	}
	else return false;
}

bool isFree(Pqueue pq) {
	if (pq->end == pq->front) {
		return true;
	}
	else return false;
}

int main(void) {

	Queue q;
	



	return 0;
}

#endif





