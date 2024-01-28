#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#if 0
typedef struct Stack {
	int top;
	int capacity;
	char* data;
}Stack,*Pstack;

void initStack(Pstack stack,int cap) {
	stack->data= (char*)malloc(cap);
	if (stack->data == NULL) {
		return;
	}
	stack->top = -1;
	stack->capacity = cap;
}

void Push(Pstack stack,char data) {
	char* arr = stack->data;
	int top = stack->top;
	if (top < (stack->capacity) - 1) {
		arr[top + 1] = data;
		stack->top = ++top;
	}
	else {
		printf("添加失败，栈区已满");
		return;
	}
}
void Pop(Pstack stack) {
	char* arr = stack->data;
	int top = stack->top;
	if (top > -1) {
		arr[top] = 0;
		stack->top = --top;
	}
	else {
		printf("移除失败，栈区内已经没有数据了");
		return;
	}
}

void ClearStack(Pstack stack) {
	char* arr = stack->data;
	int i;
	int max = stack->top;
	for (i = 0; i <= max; i++) {
		arr[i] = 0;
	}
	stack->top = -1;
}

void DestroyStack(Pstack stack) {
	free(stack->data);
}




int main(void) {
	int c;
	Stack s;
	Pstack ps = &s;
	initStack(ps, 80);
	while ((c = getchar() )!= '\n') {
		if (c != '<' && c != '#' && c != '@') {
			Push(ps, (char)c);
		}
		else if (c == '<') {
			Pop(ps);
		}
		else if (c == '@') {
			ClearStack(ps);
		}
		else {
			Push(ps, '\0');
		}
		
	}
	Push(ps, '\0');
	printf("%s",ps->data);
	DestroyStack(ps);


	return 0;
}
#endif



