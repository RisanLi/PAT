#include <cstdio>
#include <queue>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

const int maxn = 40;
int post[maxn];
int in[maxn];

Node* create(int postL, int postR, int inL, int inR){
	if (postL > postR){
		return NULL;
	}
	Node* node = new Node();
	node->data = post[postR];
	int k;
	for (k = inL; k <= inR; k++){
		if (in[k] == node->data){
			break;
		}
	}
	int leftNum = k - inL;
	//node->left = create(postL,postL + leftNum -1, inL, inL + leftNum -1);
	node->left = create(postL,postL + leftNum -1, inL, k-1);
	//node->right = create(postR - leftNum, postR -1, k + 1, k + leftNum);
	node->right = create(postL + leftNum, postR -1, k + 1, inR);
	return node;
}
int main(){
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &in[i]);
	}
	Node* root = create(0,n - 1, 0, n - 1);
	queue<Node*> q;
	q.push(root);
	int x = 1;
	while (!q.empty()){
		Node* p = q.front();
		q.pop();
		if ( x != 1) printf(" ");
		x++;
		printf("%d", p->data);
		if (p->left != NULL) q.push(p->left);
		if (p->right != NULL) q.push(p->right);
	}

	return 0;

}
