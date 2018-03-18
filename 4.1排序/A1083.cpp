#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student{
	string name;
	string id;
	int grade;
};

bool cmp(Student a, Student b){
	return a.grade > b.grade;
}

int main(){
	int n;
	cin >> n;
	vector<Student> s;
	for (int i = 0; i < n; i++){
		Student temp;
		cin >> temp.name >> temp.id >> temp.grade;
		s.push_back(temp);
	}
	sort(s.begin(),s.end(),cmp);

	int min , max;
	cin >> min >> max;
	int counter = 0;
	for (Student i : s){
		if (i.grade <= max && i.grade >= min){
			cout << i.name << " " << i.id  << "\n" ;
			counter++;
		}
	}
	if (counter == 0){
		cout << "NONE\n";
	}


	return 0;
}
