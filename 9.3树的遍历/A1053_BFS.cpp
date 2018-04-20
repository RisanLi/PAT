#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
struct Node{
	int weight;
	vector<int> children;
	int distance;	//路径和
} node[110];
vector<vector<int> > paths;
int N, M, S;

int sum = 0;
vector<int> p;
bool isLeaf[110];
void BFS(int root){
	node[root].distance = 10;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for (int i : node[temp].children){
			node[i].distance = node[i].weight + node[temp].distance;
			q.push(i);
		}
	}
}
bool cmp(vector<int> a, vector<int> b){
	int m = min(a.size(),b.size());
	for (int i = 0; i < m; i++){
		if (a[i] != b[i]){
			return node[a[i]].weight > node[b[i]].weight;
		}
	}
	return a < b;
}

int main(){
	memset(isLeaf,1,sizeof(isLeaf));
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 0; i < N; i++){
		int x;
		scanf("%d", &x);
		node[i].weight = x;
	}
	for (int i = 0; i < M; i++){
		int id, k, c;
		scanf("%d%d",&id, &k);
		isLeaf[id] = false;
		for (int j = 0; j < k; j++){
			scanf("%d", &c);
			node[id].children.push_back(c);
		}
	}
	BFS(0);
	for (int i = 0; i < N; i++){
		if (node[i].distance == S && isLeaf[i])
			printf ("%d\n",i);
	}
	return 0;
}
