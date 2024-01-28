#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <time.h>
using namespace std;

class Person {
public:
	Person(string name, int score) {
		this->name = name;
		this->average_score = score;
	}

	string name;
	int average_score;
};

void creatPerson(vector<Person>&v) {
	
	string rootname = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name = name + rootname[i];
		Person p(name, 0);
		v.push_back(p);
	}
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名 " << it->name << " " << "得分 " << it->average_score << endl;
	}

}

//deque容器应当是临时的，否则需要创建大量deque容器
void GetScore(vector<Person>&v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>de;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;
			de.push_back(score);
		}
		sort(de.begin(), de.end());
		de.pop_front();
		de.pop_back();
		int add=0;
		for (deque<int>::iterator it = de.begin(); it != de.end(); it++) {
			add += (*it);
		}
		(*it).average_score = add / 8;
		}
		for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
			cout << "姓名 " << it->name << " " << "得分 " << it->average_score << endl;
	}
}

int main(void) {
	srand((unsigned int)time(0));
	vector<Person> v;
	creatPerson(v);
	GetScore(v);
	//sort(v.begin(), v.end());
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名 " << it->name << " " << "得分 " << it->average_score << endl;
	}
	system("pause");
	
	return 0;
}


