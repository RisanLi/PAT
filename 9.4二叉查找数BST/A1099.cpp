#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
struct Node{
	int data;
	int left, right;
} node[maxn];

int n;
int arr[maxn];
int cnt = 0;
void inOrder(int root){
	if (root == -1){
		return ;
	}
	inOrder(node[root].left);
	node[root].data = arr[cnt++];
	inOrder(node[root].right);
}

void levelOrder(int root){
	queue<int> q;
	q.push(root);
	int var = 0;
	while (!q.empty()){
		int temp = q.front();
		q.pop();
		if (var++ != 0){
			printf (" ");
		}
		printf ("%d", node[temp].data);
		if (node[temp].left != -1)
			q.push(node[temp].left);
		if (node[temp].right != -1)
			q.push(node[temp].right);
	}
}

int main(){
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		int l,r;
		scanf ("%d%d", &l, &r);
		node[i].left = l;
		node[i].right = r;
	}
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		arr[i] = x;
	}
	sort(arr,arr+n);
	inOrder(0);
	levelOrder(0);
	
	return 0;
}
