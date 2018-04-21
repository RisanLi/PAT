#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int level;
	vector<int> children;
} node [110];

int levelCount[110] = {0};
int maxLevel = 1;
void BFS(int root){
	queue<int> q;
	node[root].level = 1;
	q.push(root);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		if (node[temp].children.size() == 0){
			levelCount[node[temp].level]++;
		}
		for (int i : node[temp].children){
			node[i].level = node[temp].level + 1;
			q.push(i);
			if (node[i].level > maxLevel)
				maxLevel = node[i].level;
		}
	}
}

int main(){
	int N, M;
	scanf ("%d%d",&N, &M);
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
	for (int i = 1; i <= maxLevel; i++){
		if (i != 1){
			printf (" ");
		}
		printf ("%d",levelCount[i]);
	}
	printf("\n");
	return 0;
}
