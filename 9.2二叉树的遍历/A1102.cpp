#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int notroot[10] = {0};
int findroot(){
	for (int i = 0; i < 10; i++){
		if (!notroot[i]){
			return i;
		}
	}
	return -1;
}

struct Node{
	int left, right;
}node[15];

vector<int> level;
void inverseLevelOrder(int root){
	queue<int> q;
	q.push(root);
	while (!q.empty()){
		int temp = q.front();
		q.pop();
		level.push_back(temp);
		if (node[temp].right != -1){
			q.push(node[temp].right);
		}
		if (node[temp].left != -1){
			q.push(node[temp].left);
		}
	}
}

vector<int> in;
void inverseInOrder(int root){
	if (root == -1){
		return;
	}	
	inverseInOrder(node[root].right);
	in.push_back(root);
	inverseInOrder(node[root].left);
}

int main(){
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		getchar();
		char f, s;
		int fi, si;
		scanf("%c %c",&f, &s);
		if (f >= '0' && f <= '9'){
			fi = f - '0';
			notroot[fi] = true;
			node[i].left = fi;
		}
		else 
			node[i].left = -1;
		if (s >= '0' && s <= '9'){
			si = s - '0';
			notroot[si] = true;
			node[i].right = si;
		}
		else 
			node[i].right = -1;
	}
	int root = findroot();
	inverseInOrder(root);
	inverseLevelOrder(root);
	int var = 0;
	for(int i : level){
		if (var++ != 0){
			printf(" ");
		}
		printf("%d", i);
	}
	var = 0;
	printf("\n");
	for(int i : in){
		if (var++ != 0){
			printf(" ");
		}
		printf("%d", i);
	}
	printf("\n");
	
}
