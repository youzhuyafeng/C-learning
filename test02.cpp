#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class MyVector {
public:
	typedef T* iterator;
	MyVector(int x,int y) {
		VecBg = new T(x);
		VecEd = new T(y);
	}
	

	T* VecBg;
	T* VecEd;
};








template<class T>
class Person;

template<class T>
int Plus(Person<T>& p);

template <class T>
class Person {
	friend int Plus<>(Person<T>& p);
public:
	Person(int x, int y) {
		name = x;
		age = y;
	}
private:
	int name;
	int age;
};

template<class T1>
int Plus(Person<T1>& p) {
	return p.age + p.name;
}

template <class T>
T add(T x, T y) {
	return x + y;
}

int main(void) {
	Person<int> p1(1, 2);
	cout << Plus(p1) << endl;
	int a = 10;
	int b = 20;
	add<>(a, b);
	MyVector<int> mv(10, 20);
	MyVector<int>::iterator myiter;

	vector<int> v1;
	vector<int>::iterator testit = v1.begin();
	v1.insert(testit, 10);
	for (testit; testit != v1.end(); testit++) {
		cout << *testit << " ";
	}
	return 0;
}
#endif