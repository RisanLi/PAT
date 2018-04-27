#include <cstdio>
#include <vector>
#define normal 0
#define mirror 1
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};

void insert(Node* &root, int data){
	if (root == NULL){
		root = new Node(data);
	} else if (data < root->data){
		insert(root->left, data);
	} else {
		insert(root->right, data);
	}
}

vector<int> input;
Node* create(){
	Node* root = NULL;
	for (int i : input){
		insert(root, i);
	}
	return root;
}

vector<int> pre, pre_mirror;
void preOrder(Node* root, vector<int> &v){
	if (root == NULL)
		return;
	v.push_back(root->data);
	preOrder(root->left, v);
	preOrder(root->right, v);
}
void preOrderMirror(Node* root, vector<int> &v){
	if (root == NULL)
		return;
	v.push_back(root->data);
	preOrderMirror(root->right, v);
	preOrderMirror(root->left, v);
}

vector<int> post;
void postOrder(Node* root){
	if (root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	post.push_back(root->data);
}
void postOrderMirror(Node* root){
	if (root == NULL){
		return;
	}
	postOrderMirror(root->right);
	postOrderMirror(root->left);
	post.push_back(root->data);
}

int main(){
	int n;
	scanf ("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		input.push_back(x);
	}
	Node* root = create();
	preOrder(root, pre);
	preOrderMirror(root, pre_mirror);
	bool flag_normal = true, flag_mirror = true;
	for (int i = 0; i < n; i++){
		if (pre[i] != input[i]){
			flag_normal = false;
			break;	
		}
	}
	for (int i = 0; i < n; i++){
		if (pre_mirror[i] != input[i]){
			flag_mirror = false;
			break;	
		}
	}
	if (flag_normal){		//真 则说明yes，输出后续
		printf ("YES\n");
		postOrder(root);
		int var = 0;
		for (int i : post){
			if (var++ != 0){
				printf(" ");
			}
			printf("%d", i);
		}
	} else if (flag_mirror){
		printf ("YES\n");
		postOrderMirror(root);
		int var = 0;
		for (int i : post){
			if (var++ != 0){
				printf(" ");
			}
			printf("%d", i);
		}
	
	} else {
		printf("NO\n");
	}
}
