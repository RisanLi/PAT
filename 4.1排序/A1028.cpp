/**
 * 使用cin cout读取和输出超时在此题会出现
 * 因为此题有时间限制 200ms 
 * 这次解答中 只有在string类的输入和输出的时候使用了cin cout
 * 时间已经到达191 ms 
 * 因此要养成看题的习惯 如果有题目时间限制200ms以内
 * 尽量不要使用string 类 采用传统的char str[]的方法。
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct Student{
	int id;
	string name;
	int grade;
};

bool cmp_1(Student a, Student b){
	return a.id < b.id;
}

bool cmp_2(Student a, Student b){
	if (a.name.compare(b.name) != 0) return a.name < b.name;
	else return a.id < b.id;
}

bool cmp_3(Student a, Student b){
	if (a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}

int main(){
	int n, c;
	scanf("%d%d",&n,&c);
	vector<Student> s;
	for (int i = 0; i < n; i++){
		Student temp;
		scanf ("%d",&temp.id);
		cin >> temp.name;
		scanf("%d",&temp.grade);
		s.push_back(temp);
	}
	switch (c){
		case 1 :
			sort(s.begin(),s.end(),cmp_1);
			break;
		case 2 :
			sort(s.begin(),s.end(),cmp_2);
			break;
		case 3 :
			sort(s.begin(),s.end(),cmp_3);
			break;
	}
	for (Student i : s){
		printf("%06d ",i.id);
		printf("%s %d",i.name.c_str(),i.grade);	
		printf("\n");
	}
	return 0;
}
