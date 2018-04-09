#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;
int hashCode(char str[]){
	int temp = 0, base = 1;
	for (int i = 0; i < 3; i++){
		temp += (str[i]-'A') * base;
		base *= 26;
	}
	temp += (str[3] - '0') * base;
	return temp;
}

vector<int> list[600000];
int main(){
	int n, k;	//n代表学生数量,k代表查询总人数
	cin >> n >> k;

	for (int i = 0; i < k; i++){
		int index, m;	//index 代表课程号，m代表学生人数
		scanf ("%d%d",&index, &m);
		for (int j = 0; j < m; j++){
			char stuName[5];
			scanf("%s",stuName);
			list[hashCode(stuName)].push_back(index);
		}
	}

	//输出
	for (int i = 0; i < n; i++){
		char stuName[5];
		scanf("%s",stuName);
		cout << stuName << " ";
		printf("%d", list[hashCode(stuName)].size());
		sort(list[hashCode(stuName)].begin(),list[hashCode(stuName)].end());
		for(int i : list[hashCode(stuName)]){
			printf (" %d",i);
		}
		printf ("\n");
	}

}
