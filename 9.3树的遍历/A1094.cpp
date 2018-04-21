#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
struct Node{
	int level;
	vector<int> children;
} node[110];

int total[110] = {0};	//每层的节点的个数

void BFS(int root){
	node[root].level = 1;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for (int i : node[temp].children){
			node[i].level = node[temp].level + 1;
			q.push(i);
			total[node[i].level]++;
		}
	}
}
int main(){
	int N, M;
	scanf ("%d%d", &N, &M);
	for (int i = 0; i < M; i++){
		int id, k;
		scanf ("%d%d", &id, &k);
		for (int j = 0; j < k; j++){
			int c;
			scanf ("%d", &c);
			node[id].children.push_back(c);
		}
	}
	BFS(1);
	int max = -1, point = -1;
	total[1] = 1;
	for (int i = 2; i <= N; i++){
		if (total[i] > max){
			point = i;
			max = total[i];
		}
	}
	if (point != -1)
		printf ("%d %d\n", total[point], point);
	else
		printf ("1 1\n");

	return 0;
}
