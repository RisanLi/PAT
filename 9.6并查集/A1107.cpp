#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1010;
struct Person{
	vector<int> hobby;
} person[maxn];

int father[maxn];
int root[maxn] = {0};
int findFather(int x){
	if (x == father[x]){
		return x;
	} else {
		return findFather(father[x]);
	}
}

void combineFather(int a, int b){	//整合父节点 无论是
	int aFather = findFather(a);
	int bFather = findFather(b);
	if (aFather != bFather){
		father[bFather] = aFather;
	}
}

void init(){		//初始化把所有节点的父节点定义为自己
	for (int i = 0; i < maxn; i++){
		father[i] = i;
	}
}
int n;
void finish(){		//求结果，求每个人的父节点，并计算各个父节点个数
	for (int i = 0; i < n; i++){
		root[findFather(person[i].hobby[0])]++;	
	}
}
bool cmp(int a, int b){
	return a > b;
}

int main(){
	init();
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		int m;
		scanf("%d: ",&m);
		for (int j = 0; j < m; j++){
			int h;
			scanf ("%d", &h);
			person[i].hobby.push_back(h);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < (int)person[i].hobby.size()-1; j++){
			combineFather(person[i].hobby[j],person[i].hobby[j+1]);	
		}
	}
	finish();
	sort(root,root+maxn,cmp);
	int cnt = 0;
	for (int i = 0; i < maxn; i++){
		if (root[i] >0)
			cnt++;
		else 
			break;
	}
	printf ("%d\n", cnt);
	for (int i = 0; i < cnt; i++){
		if (i != 0)
			printf (" ");
		printf ("%d",root[i]);
	}
	printf("\n");
	return 0;
}
