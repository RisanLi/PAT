#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
	string ID;
	int virtue;
	int talent;
	int sum;
};

bool cmp(Student a, Student b){
	if(a.sum != b.sum) return a.sum > b.sum;
	else if (a.virtue != b.virtue) return a.virtue > b.virtue;
	else return a.ID < b.ID;
}

int main(){
	int n,l,h;	//n是学生总数，l最低线，h最高线
	vector<Student> bothTalentVirtue, onlyVirtue, neitherButVirtueMore,others;

	cin >> n >> l >> h;
	for (int i = 0; i < n; i++){
		Student temp;
		cin >> temp.ID >> temp.virtue >> temp.talent;
		temp.sum = temp.virtue + temp.talent;
		if (temp.virtue >= h && temp.talent >= h){
			bothTalentVirtue.push_back(temp);
		} 
		else if (temp.virtue >= h && temp.talent < h && temp.talent >= l){
			onlyVirtue.push_back(temp);
		}
		else if (temp.virtue < h && temp.talent < h && temp.virtue >= temp.talent && temp.virtue >= l && temp.talent >= l ){
			neitherButVirtueMore.push_back(temp);
		}
		else if (temp.virtue >= l && temp.talent >= l){
			others.push_back(temp);
		}
	}
	sort(bothTalentVirtue.begin(),bothTalentVirtue.end(),cmp);
	sort(onlyVirtue.begin(),onlyVirtue.end(),cmp);
	sort(neitherButVirtueMore.begin(),neitherButVirtueMore.end(),cmp);
	sort(others.begin(),others.end(),cmp);

	cout << bothTalentVirtue.size() + onlyVirtue.size()
		+ neitherButVirtueMore.size() + others.size() << "\n";
	for (Student i : bothTalentVirtue){
		cout << i.ID <<" " << i.virtue <<" " << i.talent << "\n";
	}
	for (Student i : onlyVirtue){
		cout << i.ID <<" " << i.virtue <<" " << i.talent << "\n";
	}
	for (Student i : neitherButVirtueMore){
		cout << i.ID <<" " << i.virtue <<" " << i.talent << "\n";
	}
	for (Student i : others){
		cout << i.ID <<" " << i.virtue <<" " << i.talent << "\n";
	}
	
	
	


	return 0;
}
