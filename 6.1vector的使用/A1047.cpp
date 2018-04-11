#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
struct Cstring{
	char name[10];
};
bool cmp(Cstring a,Cstring b){
	return strcmp(a.name,b.name) < 0;
}


int main(){
	vector<Cstring> course[2510];
	int n,k;	
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < n; i++){
		char stuName[10];
		scanf("%s",stuName);
		int sum;
		Cstring s;
		strcpy(s.name,stuName);
		scanf ("%d", &sum);
		for (int j = 0; j < sum; j++){
			int index;
			scanf("%d",&index);
			course[index].push_back(s);
		}
	}
	for (int i = 1; i <= k; i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(Cstring str:course[i]){
			printf("%s\n",str.name);
		}
	}
	return 0;
}
