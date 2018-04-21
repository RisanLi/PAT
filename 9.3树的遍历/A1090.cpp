#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N;
double P, R;

struct Node{
	double price;
	vector<int> children;
} node[100010];

vector<int> vLeaf;
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
		if (node[temp].children.empty()){
			vLeaf.push_back(temp);
		}
	}
}

int main(){
	int r ;
	scanf("%d%lf%lf", &N, &P, &R);
	for (int i = 0; i < N; i++){
		int f;
		scanf ("%d", &f);
		if (f != -1){
			node[f].children.push_back(i);
		}
		if (f == -1)
			r = i;
	}
	BFS(r);
	double sum = 0;
	int cnt = 0;
	for (int i : vLeaf){
		if (node[i].price > sum){
			sum = node[i].price;
			cnt = 1;
		} else if (node[i].price == sum){
			cnt++;
		}
	}
	printf("%.2lf %d\n", sum,cnt);

	return 0;
}

