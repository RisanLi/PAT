#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Vertix{
	int v;
	int weight;
};

const int maxn = 20000;		//26^3+26^2+26 < 20000
bool visit[maxn] = {false};	//表示某个节点是否被访问
int verWeight[maxn] = {0};	//点权值
vector<Vertix> adj[maxn];	//邻接表 范围大于1000 用邻接表
vector<int> gang[maxn];		//gang[i]组 中存放的是该组所有成员
int belong[maxn];			//该人属于哪个gang组

int nameToInt(char str[]){	//该人名转为int 方便数组的使用
	int a = 0;
	for (int i = 0; i < 3; i++){
		a = a * 26 + str[i] - 'A';
	}
	return a;
}

void intToName(int x){		//从int转为人名
	char r[4];
	for (int i = 2; i >= 0; i--){
		r[i] = 'A' + x % 26;
		x = (x - x % 26) / 26;
	}
	for (int i = 0; i < 3; i++){
		printf("%c",r[i]);
	}
}

bool cmp(int a, int b){
	return verWeight[a] > verWeight[b];
}

void DFS(int x, int gangCount){	//对已形成的图进行遍历
								//把遍历到的节点放入该gang组中
	if (visit[x])
		return;
	visit[x] = true;
//	printf("节点:");
//	intToName(x);
//	printf("进入gang[%d]", gangCount);
//	printf("\n");
	gang[gangCount].push_back(x);
	belong[x] = gangCount;
	for (Vertix v : adj[x]){
		verWeight[x] += v.weight;
		verWeight[v.v] += v.weight;
		DFS(v.v, gangCount);
	}
}

int totalEdgeWeight(vector<int> v){	//求该gang组边权值
	int sum = 0;
	for (int i : v){
		for (Vertix vet : adj[i]){
			sum += vet.weight;
		}
	}
	return sum;
}
int main(){
	for (int &i : belong){
		i = -1;
	}
	int n, threshold;	
	scanf ("%d%d", &n, &threshold);
	set<int> putin;
	for (int i = 0; i < n; i++){
		char first[5], second[5];
		scanf ("%s%s",first,second);
		int weight;
		scanf ("%d", &weight);
		int x = nameToInt(first);
		int y = nameToInt(second);
	//	printf("x = %d y = %d\n",x,y);
		Vertix temp;
		temp.v = y;
		temp.weight = weight;
		adj[x].push_back(temp);
		putin.insert(x);
		putin.insert(y);
	}
	int count = 0;	// gang[]从1开始数
	for (int i : putin){
	//	printf("%d  ",i);
	//	printf("%d  ",belong[i]);
		if (belong[i] == -1){
			count++;
			DFS(i,count);
		}
	}
	vector<int> output;
	for (int i = 1; i <= count; i++){
	//	printf("gang[%d]的size = %d\n",i,(int)gang[i].size());
		if (gang[i].size() > 2){
			sort(gang[i].begin(),gang[i].end(),cmp);
		//	printf("verWeight = %d\n",verWeight[gang[i].front()]);
			if (totalEdgeWeight(gang[i]) > threshold)
				output.push_back(gang[i].front());
		}
	}
	sort(output.begin(),output.end());
	printf("%d\n",(int)output.size());
	for (int i : output){
		intToName(i);
		printf(" ");
		printf("%d\n",(int)gang[belong[i]].size());
	}
	
	return 0;

}
