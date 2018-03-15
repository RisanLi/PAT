/**
 *
 * 对于准考证号，id号一类的多位数字一定使用字符串的格式
 * 否则如果使用 数字的格式在输出的时候会出现 前面的0会自动省略的情况
 *
 */



#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Testee{
	long long regNumber;	//注册编号
	int Score;
	int finalRank;			//总排名
	int localNumber;		//考场号
	int localRank;			//考场排名
};

bool cmp(Testee a, Testee b){
	if (a.Score != b.Score) 
		return a.Score > b.Score;
	else
		return a.regNumber < b.regNumber;
}


int main(){
	int n;		//N 组数据
	int k;		//每个考场人数
	vector<Testee> allTestee;
	cin >> n;
	if (n == 0) return 0;
	for(int i = 0; i < n; i++){
		cin >> k;
		if (k == 0) continue;
		vector<Testee> localTestee;
		for (int j = 0; j < k; j++){
			Testee temp;
			cin >> temp.regNumber;
			cin >> temp.Score;
			temp.localNumber = i+1;
			localTestee.push_back(temp);
		}
		sort (localTestee.begin(),localTestee.end(),cmp);
		localTestee[0].localRank = 1;
		for (int j = 1; j < k; j++){
			if (localTestee[j].Score == localTestee[j-1].Score){
				localTestee[j].localRank = localTestee[j-1].localRank;
			}
			else{
				localTestee[j].localRank = j + 1;
			}
		}
		
		allTestee.insert(allTestee.end(),localTestee.begin(),localTestee.end());
	}
	sort (allTestee.begin(),allTestee.end(),cmp);
	allTestee[0].finalRank = 1;
	for (int i = 1; i < allTestee.size(); i++){
		if(allTestee[i].Score == allTestee[i-1].Score){
			allTestee[i].finalRank = allTestee[i-1].finalRank;
		}
		else{
			allTestee[i].finalRank = i + 1;
		}
	}
	cout << allTestee.size() <<"\n";
	for (Testee i : allTestee){
		printf("%013lld ",i.regNumber);
		cout << i.finalRank << " ";
		cout << i.localNumber << " ";
		cout << i.localRank<<"\n";
	}
	return 0;
}
