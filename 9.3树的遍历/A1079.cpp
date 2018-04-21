#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N;
double P, R;

struct Node{
	double price;
	vector<int> children;
	int amount;
} node[100010];

void BFS(int root){
	queue<int> q;
	node[root].price = P;
	q.push(root);
	while (!q.empty()){
		int temp = q.front();
		q.pop();
		for (int i : node[temp].children){
			node[i].price = node[temp].price * (1 + R / 100);
			q.push(i);
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
			vLeaf.push_back(i);
			int amount;
			scanf ("%d", &amount);
			node[i].amount = amount;
		}
	}
	BFS(0);
	double sum = 0;
	for (int i : vLeaf){
		sum += node[i].amount * node[i].price;
	}
	printf("%.1lf\n", sum);

	return 0;
}

