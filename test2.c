#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void isPrime(int i)
{
	int j = 0;
	for (j = 2; j <= 13; j++)
		if (i % j == 0)
			break;
	if (j == 14)
	{
		printf("%d是素数\n", i);
	}
	
}

long long fabor(int a)
{
	int i = 1;
	int j = 1;
	int m = 0;
	int k = 1;
	for (k = 3; k <= a; k++)
	{
		m = i + j;
		i = j;
		j = m;
	}
	return m;

}

void Bubble_Sort(int* px, int sz)
{
	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		int j = 0;
		for (j = 0; j < sz-i-1; j++)
		{
			int temp = 0;
			if (*(px + j) >= *(px + 1 + j))
			{
				temp = *(px + j);
				*(px + j) = * (px + 1 + j);
				* (px + 1 + j) = temp;
			}
		}
	}
}

struct Stu
{
	int arr[10];
	char sarr[10];
};

void write(struct Stu * ps)
{
	char s[6] = "david";
	strcpy((*ps).sarr,s);
	
}

void reverse(char* ps,int strlen){
	int left = 0;
	int right = strlen - 1;
	while (left < right) {
		char temp;
		temp = *(ps + left);
		*(ps + left) = *(ps + right);
		*(ps + right) = temp;
		left++;
		right--;
	}
}
//
//int WordLength(char* pw) {
//	int i = 0;
//	while (*(pw+i) != " ") {
//		i++;
//	}
//	return i;
//}

void my_strcpy(char* ps1, const char* ps2)
{
	while (*ps2)
	{
		*ps1++ = *ps2++;
	}
	*ps1 = '\0';
}


void change(int* pa, int strlen)
{
	int left = 0;
	int right = strlen - 1;
	while(left < right)
	{
		if (*(pa + left) % 2 == 0)
		{
			left++;
			continue;
		}
		if (*(pa + right) % 2 == 1)
		{
			right--;
			continue;
		}
		int temp = 0;
		temp = *(pa + left);
		*(pa + left) = *(pa + right);
		*(pa + right) = temp;
		left++;
		right--;
	}

}

//void* my_memcpy(void* dest, void* sour, unsigned int length)
//{
//	void* p = dest;
//	dest = (char*)dest + length-1;
//	sour = (char*)sour + length-1;
//	int i;
//	for (i = 0; i < length; i++)
//	{
//		*(char*)dest = *(char*)sour; //尽量不要写++，对临时变量++
//		dest = (char*)dest - 1;
//		sour = (char*)sour - 1;
//	}
//	return p;
//}


enum COLOR {
	red=1,
	green,
	blue,
};

struct text {
	int* arrtest;
	const int* arr;
};








	//int b = 1;
	//scanf("%d", &b);
	//switch (b)
	//{
	//case 1:
	//	printf("星期一");
	//case 2:
	//	printf("星期二");
	//default:
	//	printf("不知道");
	//	break;
	//return 0;
	//}
	//char b = '\0';
	//if ((b = getchar()) > 48)
	//	printf("b=%d", b);
	//else
	//	printf("什么都没有");
	//long tel = 0;
	//float score1 = 0.0f;
	//float score2 = 0;
	//float score3 = 0;
	//scanf("%ld;%f,%f,%f", &tel, &score1, &score2, &score3);
	//printf("电话号%d", tel);
	//printf("分数 %.2f %.2f %.2f", score1, score2, score3);
	/*int a = 0;
	scanf("%d", &a);
	if ('a' == a)
		printf("正确的");*/
	//int a = 0;
	//int i = 0;
	//int n = 1;
	//scanf("%d", &a);
	//for (i = 1; i <= a; ++i)
	//	n *= i;
	//printf("%d", n);
	//return 0;
	// 
	//int a = 0;
	//int i = 1;
	//int n = 1;
	//scanf("%d", &a);
	//while (i <= a)
	//{
	//	n *= i;
	//	i++;
	//}
	//printf("%d", n);
	//return 0;
	//int a = 0;
	//int i = 1;
	//int n = 1;
	//scanf("%d", &a);
	//do 
	//{
	//	n *= i;
	//	i++;
	//}
	//while (i<=a);
	//printf("%d", n);
	/*int i = 0;
	int n = 1;
	int s = 0;
	for (i=1;i<=10;++i)
	{
		n *= i;
		s += n;
	}
	printf("%d", s);


	return 0;*/
	//int arr[10] = { 10,51,22,841,4194,3,319 };
	//int arrlen = sizeof(arr) / sizeof(arr[0]);
	//int i = 0;
	//int find = 3;
	//int k = 1;
 //   //基于for循环的性质，每次循环体结束后先跳到++i再进行判断，于是如果i如果等于必定是没找到
	//for (i = 0; i < arrlen; ++i)
	//{
	//	if (arr[i] == find)
	//	{
	//		printf("%d", i);
	//		break;
	//	}

	//}
	//if (i == arrlen)
	//	printf("找不到");

	//char str1[] = "welcome to beijing!";
	//char str2[] = "###################";
	//int i = 0;
	//int j = strlen(str1) - 1;
	//for (i, j; i <= j; ++i, --j)
	//{
	//	str2[i] = str1[i];
	//	str2[j] = str1[j];
	//	printf("%s\n", str2);

	//int num = 76;
	//int min = 0;
	//int max = 100;
	//int guess = 0;
	//int i = 1;
	//while (i)
	//{
	//	printf("请输入数字\n");
	//	scanf("%d", &guess);
	//	if (guess < num)
	//	{
	//		min = guess + 1;
	//		printf("你猜测的数字小了，请在%d-%d之间猜测\n", min, max);
	//		continue;
	//	}
	//	else if (guess > num) 
	//	{
	//		max = guess - 1;
	//	    printf("你猜测的数字大了，请在%d-%d之间猜测\n", min, max);
	//		continue;
	//	}
	//	else
	//	{
	//		printf("猜对了\n");
	//		break;
	//}

//for (i = 100; i <= 200; i++)
//{
//	isPrime(i);
//}

//int i = 0;
//iplus(&i);
//iplus(&i);
//iplus(&i);
//iplus(&i);
//printf("%d", i);

//int arr[] = { 9,8,7,6,5,4,3,2,1 };
//int sz = sizeof(arr) / sizeof(arr[0]);
//Bubble_Sort(arr,sz);

//int arr1[4] = { 1,2,3,4 };
//int arr2[4] = { 2,3,4,5 };
//int arr3[4] = { 3,4,5,6 };
//int* parr[3] = { arr1,arr2,arr3 };
//int i = 0;
//for (i = 0; i < 3; i++)
//{
//	int j = 0;
//	for (j = 0; j < 4; j++)
//	{
//		printf("%d ", *(parr[i] + j));//等价于parr[i][j]
//	}
//	printf("\n");
//}

//char str[10] = { 0 };
//printf("请输入密码");
//scanf("%s", str);
//if (strcmp("abc123",str) == 0)
//{
//	printf("正确");
//}

//struct Stu s = { 0 };
//write(&s);
//int line = 0;
//scanf("%d", &line);
//int i = 0;
//int j = 0;
//int k = 0;
//int middle = 0;
//middle = line / 2 + 1;
//
//for (i = 1; i <= line; i++)
//{
//	if (i <= middle)
//	{
//		for (j = 1; j <= middle  - i; j++)
//		{
//			printf(" ");
//		}
//		for (k = 1; k <= 2 * i - 1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}
;
//char test[100] = "This is a test string.";
//int length = strlen(test);
//reverse(test, length);
//int i = 0;
//int j = 0;
//int begin = 0;
//for (i = 0; i <= length; i++) {
//	if (*(test + i) != ' ' && (*(test + i) != '\0')){
//		j++;
//		continue;
//	}
//	reverse(test + begin,j);
//	begin = i + 1;
//	j = 0;
//}
//
//printf("%s", test);

//char str2[100] = "this is a test str.";
//char str1[100];
//

//my_strcpy(str1,str2);
//printf("%s", str1);
//
//int arr[10] = { 0,3,5,6,8,1,7,9,2,4 };
//int sz = sizeof(arr) / sizeof(arr[0]);
//change(arr, sz);
//int i = 0;
//for (i = 0; i < sz; i++) {
//	printf("%d ", arr[i]);
//}

//int arr1[5] = { 1,2,3,4,5 };
//int arr2[5] = { 2,3,4,5,6 };
//int arr3[5] = { 3,4,5,6,7 };
//int* arr[3] = { arr1, arr2, arr3 };
//int i = 0;
//for (i = 0; i < 5; i++) {
//	printf("%d", *(arr[0] + i));
//}
//printf("\n");
//int arr4[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//int(*p1)[5];
//int k = 0;
//for (k = 0; k < 3; k++)
//{
//	int m = 0;
//	int(*p1)[5] = arr4+k;
//	for (m = 0; m < 5; m++)
//	{
//		printf("%d ", *(*p1 + m));
//	}
//	printf("\n");
//}
//int(*karr)[10];                           //数组指针
//int (* p10)(int, int);                    //函数指针
//int (* narr[10])(int, int);               //函数指针数组
//int(*(*parr)[10])(int,int) = &narr;       //函数指针数组的指针

//int arrt[] = { 1,2,3,4,5,6,7,8,9,0 };
//int arrk[20] = { 0 };
//my_memcpy(arrt+2, arrt, 20);
//int d;
//for (d = 0; d < 10; d++)
//{
//	printf("%d ", arrt[d]);
//}

//typedef struct Node {
//	char name[10];
//	struct Node* next;
//}*pstu;
//typedef struct Node HAHA;
//HAHA stu3 = { "xiaohong",NULL };
//HAHA stu2 = {"xiaoming",&stu3};
//HAHA stu1 = {"xiaobai",&stu2};
//HAHA stuset[10] = { stu1,stu2,stu3 };
//pstu p = &stu1;
//printf("%s", p->next->next->name);
//printf("\n");
//enum COLOR h = red;
//printf("%d", sizeof(h));
//struct text a;
//struct text* pt = &a;      
//pt->arrtest = (int*)malloc(40);
//int a = 1;
//pt->arr = &a;
//(*pt).arr = 2;
//printf("\n%d",(*pt).arr);
//return 0;


