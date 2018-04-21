#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int N;
double P, R;

struct Node{
	double price;
	vector<int> children;
	int level;
} node[100010];
int total[100010] = {0}; 	//该层叶子节点总数量
bool isLeaf[100010] = {0};
void BFS(int root){
	queue<int> q;
	q.push(root);
	node[root].level = 1;
	total[root] = 1;
	while (!q.empty()){
		int temp = q.front();
		q.pop();
		for (int i : node[temp].children){
			node[i].level = node[temp].level + 1;
			q.push(i);
			if (isLeaf[i])
				total[node[i].level]++;
		}
	}
}

int main(){
	vector<int> vLeaf;
	scanf("%d%lf%lf", &N, &P, &R);
	for (int i = 0; i < N; i++){
		int k;
		scanf("%d", &k);
		if (k != 0){
			for (int j = 0; j < k; j++){
				int c;
				scanf ("%d", &c);
				node[i].children.push_back(c);
			}
		} else {
			isLeaf[i] = true;
			vLeaf.push_back(i);
		}
	}
	BFS(0);
	int min = 100010;
	for (int i : vLeaf){
		if (node[i].level < min){
			min = node[i].level;
		}
	}
	if (N != 1)
		printf("%.4lf %d\n", P*pow(1+R/100,min-1), total[min]);
	else
		printf("%.4lf 1\n",P);
	return 0;
}

