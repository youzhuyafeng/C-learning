#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if 0
typedef struct node {
	int age;
	struct node* pnode;
}NODE,*PNODE;


typedef struct double_node {
	struct double_node* prior;
	int age;
	struct double_node* last;
}DNODE,*PDNODE;




//链表插入接口
PNODE insertNode(PNODE head,int n,int age) {
	PNODE pnew = (PNODE)malloc(sizeof(NODE));
	if (pnew == NULL) {
		return NULL;
	}
	PNODE p = head->pnode;
	for (int i = 0; i < n; i++) {
		p = p->pnode;
	}
	pnew->pnode = p->pnode;
	p->pnode = pnew;
	pnew->age = age;
	return head;

}
bool DelateNode(PNODE head, int x) {
	PNODE find = head->pnode;
	PNODE find_hind = head;
	int i;
	while (find && (find->age)!=x){
		if (find != x){
			find_hind = find;
			find = find->pnode;
		}
		else {
			find_hind = find->pnode;
			free(find);
			find = NULL;
			return true;
		}
	}
	return false;
}
//头插法建立链表接口
PNODE newList1(int arr[], int length) {
	PNODE head = (PNODE)malloc(sizeof(NODE));
	if (head == NULL) {
		return NULL;
	}
	head->pnode = NULL;
	int i;
	for (i = 0; i < length; i++) {
		PNODE new = (PNODE)malloc(sizeof(NODE));
		if (new == NULL) {
			return NULL;
		}
		new->age = arr[i];
		new->pnode = head->pnode;
		head->pnode = new;
	}
	return head;
}
//尾插法建立链表接口
PNODE newList2(int arr[], int length) {
	PNODE head = (PNODE)malloc(sizeof(NODE));
	if (head == NULL) {
		return NULL;
	}
	head->pnode = NULL;
	PNODE last = head;
	int i;
	for (i = 0; i < length; i++) {
		PNODE new = (PNODE)malloc(sizeof(NODE));
		if (new == NULL) {
			return NULL;
		}
		new->age = arr[i];
		new->pnode = NULL;
		last->pnode = new;
		last = new;
	}
	return head;
}

//双向链表插入
DNODE insertDnode(PDNODE head, int pos, int age_data) {
	PDNODE new = (PDNODE)malloc(sizeof(DNODE));
	if (new == NULL) {
		return;
	}
	int i;
	PDNODE prior_of_find = head;
	PDNODE find = head->last;
	for (i = 0; i <= pos; i++) {
		prior_of_find = find;
		find = find->last;
	}
	new->last = prior_of_find->last;
	prior_of_find = new;
	new->prior = find->prior;
	find->prior = new;

}

#endif






















