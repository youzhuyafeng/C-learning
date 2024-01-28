#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
//#include <__msvc_all_public_headers.hpp>
//#include <bits/stdc++.h>
using namespace std;

int arr[5] = { 0,1,2,3,4 };

int& test02(int x) {
	return arr[x];
}


void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

class Stu {
public:
	int age;
	char n_name[10];
	void set_name(char* name) {
		strcpy(n_name, name);
	}
};


class Phone {
public:
	Phone() {
		m_size = 5;
		m_creator = "huawei";
		cout << "Phone默认构造函数" << endl;

	}
	Phone(int size,const char*creator) {
		m_size = size;
		m_creator = creator;
		cout << "Phone有参构造函数" << endl;
	}
	~Phone() {
		cout << "Phone析构函数" << endl;
	}
	int m_size;
	const char* m_creator;
};

class Person {
public:
	Person() {
		age = 18;
		a = new int(0);
		cout << "Person默认构造函数" << endl;
	}

	//Person(int age,int size,const char*creator){
	//	(*this).age = age;
	//	Phone p1(size, creator);
	//	m_phone = p1;
	//	cout << "Person参数构造函数" << endl;
	//}
	~Person() {
		if (a != NULL) {
			delete a;
			a = NULL;
			cout << "Person析构函数" << endl;

		}
	}
	ostream& operator<<(Person* p);
	Person& operator=(Person& p);
	int age;
	int* a;
	static int k;
	Phone m_phone;
};
int Person::k = 0;

ostream& Person::operator<<(Person* p) {
	cout<<(*p).age;
	return cout;
}

Person& Person::operator=(Person& p) {
	if (a!=NULL) {
		delete a;
		a = NULL;
	}
	this->a = new int(*p.a);
	return *this;
}

int& newtest(int x) {
	int* p = new int(x);

	return *p;
}


//template <class T>
//class Person1 {
//	friend Add<>(Person1<T>& p);
//private:
//	T m_age;
//	T m_grade;
//};
//
//template <class T>
//T Add(Person1<T>& p) {
//	return p.m_age + p.m_grade;
//}



class Animal {
	friend int plus(Animal& a) {
		return a.m_Age + a.m_Mom;
	}
public:
	Animal(int x,int y) {
		m_Age = x;
		m_Mom = y;
	}

	template <class T>
	T Add(T x, T y);
private:
	int m_Age;
	int m_Mom;
};

template <class T>
T Animal::Add(T x, T y) {
	return x + y;
}

class Sheep :virtual public Animal {};
class Lama :virtual public Animal {};
class SheepLama :public Sheep, public Lama{};

class Calculator {
public:
	Calculator() {
		x = 0;
		y = 0;
	}
	Calculator(int x1, int y1) {
		x = x1;
		y = y1;
	}
	virtual int GetResult() {
		return x;
	}
	int x;
	int y;
};

class Plus :public Calculator {
public:
	int GetResult() {
		return x + y;
	}
};

class Sub :public Calculator {
public:
	
	Sub(int x,int y,int z):Calculator(x,y){
		this->z = new int(z);
	}
	~Sub() {
		cout << "sub析构函数使用" << endl;
		delete z;
		z = NULL;
	}
	int GetResult() {
		return x - y;
	}
	int* z;
};


template <class T>
void ChooseSort(T* arr, int len) {
	int end = len - 1;
	int i;
	int j;
	for (i = 1; i <= end; i) {
		int max = 0;
		for (j = 1; j <= end; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
			else { continue; }
		}
		T temp = arr[max];
		arr[max] = arr[end];
		arr[end] = temp;
		end--;

	}
}

void cal(Calculator& c) {
	cout << c.GetResult() << endl;
}
int main(void) {
	cout << "hello world" << endl;
	int i;
	int j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cout << i << "*" << j << "=" << i * j;
			cout << "  ";
		}
		cout << endl;
	}

	//system("pause");
	Person p1(15, 8, "oppo");
	Person p2(20, 10, "vivo");
	p1 = p2;
	cout << p1.m_phone.m_creator << endl;
	cout << p1.m_phone.m_size << endl;
	int p = newtest(10);
	cout << p << endl;

	int tarr[10] = { 6,4,7,8,9,3,2,0,1,5 };
	double darr[10] = { 1.3,3.3,8.3,5.3,7.3,2.3,0.3,6.3,9.3,4.3 };
	ChooseSort(darr, sizeof(darr) / sizeof(darr[0]));
	for (int i = 0; i < 10; i++) {
		cout << darr[i]<<" ";
	}
	cout << endl;

	Animal an(1,2);
	cout << an.Add(10, 11) << endl;
	cout << plus<>(an) << endl;
	return 0;



}
#endif



