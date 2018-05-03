#include <cstdiointint  >
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		int height;
		int row;
		Node(int v){
			this->data = v;
			this->left = this->right = NULL;
			this->height = 1;
		}
};

int getHeight(Node* root){
	if (root == NULL)
		return 0;
	else 
		return root->height;
}

int getBalanceFactor(Node* root){
	return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(Node* root){
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
}

void R(Node* &root){
	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root = temp;
}

void L(Node* &root){
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root = temp;
}

void insert(Node* &root, int v){
	if (root ==NULL){
		root = new Node(v);
		return;
	}
	if (v < root->data){
		insert(root->left,v);
		updateHeight(root);
		if (getBalanceFactor(root) == 2){	//LL or LR
			if (getBalanceFactor(root->left) == 1){
				R(root);				
			} else{
				L(root->left);
				R(root);
			}
			updateHeight(root->left);
			updateHeight(root->right);
			updateHeight(root);
		}
	} else {
		insert(root->right,v);
		updateHeight(root);
		if (getBalanceFactor(root) == -2){	//RR or RL
			if (getBalanceFactor(root->right) == -1){
				L(root);
			} else {
				R(root->right);
				L(root);
			}
			updateHeight(root->left);
			updateHeight(root->right);
			updateHeight(root);
		}
	}
}
vector<int> v;
void BFS(Node* root, int n){
	queue<Node*> q;
	root->row = 1;
	q.push(root);
	int maxRow = (int)log10(n)/log10(2) + 1;
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		v.push_back(temp->data);
		if (temp->left != NULL){
			q.push(temp->left);
		}
		if (temp->right!= NULL){
			q.push(temp->right);
		}
	}
}

bool judge(Node* root,int n){
	queue<Node*> q;
	q.push(root);
	while(n){
		Node* front = q.front();
		if(front == NULL){
			return false;
		}
		q.push(front->left);
		q.push(front->right);
		q.pop();
		n--;
	}
	return true;
}
int main (){
	int n;
	scanf ("%d",&n);
	Node* root = NULL;
	for (int i = 0; i < n; i++){
		int x;
		scanf ("%d", &x);
		insert(root,x);
	}
	BFS(root,n);
	for (int i = 0; i < n; i++){
		if (i != 0)
			printf(" ");
		printf("%d",v[i]);
	}
	if (judge(root,n)){
		printf("\nYES\n");
	} else {
		printf("\nNO\n");
	}
	return 0;
}
