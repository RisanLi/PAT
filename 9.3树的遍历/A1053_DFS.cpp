#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
struct Node{
	int weight;
	vector<int> children;
} node[110];
vector<vector<int> > paths;
int N, M, S;

int sum = 0;
vector<int> p;
bool isLeaf[110];
void DFS(int root){		//根序遍历
	if (sum > S)	//剪枝
		return;
	//访问节点
	sum += node[root].weight;
	p.push_back(root);
	//访问孩子节点
	for (int i : node[root].children){
		DFS(i);
		p.pop_back();	//访问完一个节点要弹出该节点类似二叉树的DFS
		sum -= node[i].weight;
	}

	//边界的放置位置要带入例子具体确定
	if (sum == S && isLeaf[p.back()]){	//边界
		paths.push_back(p);
	//	sum -= node[p.back()].weight;
	//	p.pop_back();
		return;
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
	DFS(0);
	sort(paths.begin(),paths.end(),cmp);
	for (vector<int> i : paths){
		int var = 0;
		for (int j : i){
			if (var++ != 0)
				printf (" ");
			printf ("%d", node[j].weight);
		}
		printf ("\n");
	}
	return 0;
}
