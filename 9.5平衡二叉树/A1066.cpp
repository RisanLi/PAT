#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Node {
	public:
		int data;	//权值
		int height;	//高度
		Node* left;	//左右孩子
		Node* right;
		int rank;	//行数
		Node(int v){
			this->data = v;
			this->height = 1;
			this->right = NULL;
			this->left = NULL;
		}
};

int getHeight(Node* root){
	if (root == NULL)
		return 0;
	return root->height;
}

int getBalanceFactor(Node* root){
	return getHeight(root->left) - getHeight(root->right);
}

void updataHeight(Node* root){
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
}
//左旋
void L(Node* &root){
//	printf("左旋\n");
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
//	updataHeight(root);
//	updataHeight(temp);
	root = temp;
}

//右旋
void R(Node* &root){
//	printf("右旋\n");
	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
//	updataHeight(temp);
//	updataHeight(root);
	root = temp;
}

void insert(Node* &root, int v){		
	if (root == NULL){
//		printf ("节点 %d 插入成功", v);
		Node* node = new Node(v);
		root = node;
		return;
	}
	if (v < root->data){
		insert(root->left,v);
		updataHeight(root);
		//插入左孩子 因此平衡因子只可能出现2的情况
		if (getBalanceFactor(root) == 2){	//LL型或者LR型
			if(getBalanceFactor(root->left) == 1){	//LL型
				R(root);
			} else if (getBalanceFactor(root->left) == -1){ 
				L(root->left);
				R(root);
			}
			updataHeight(root);
			updataHeight(root->left);
			updataHeight(root->right);
		}
		//正常情况下 平衡因子因改为0 或者 1
	} else{ //if (v > root->data){
		insert(root->right,v);
		updataHeight(root);
		if (getBalanceFactor(root) == -2){ //RR型或者RL型
			if (getBalanceFactor(root->right) == -1){ //RR
				L(root);
			} else if (getBalanceFactor(root->right) == 1){ 
				R(root->right); 			//子树根节点不发生改变
				L(root);					//改变子树根节点
			}
			updataHeight(root);
			updataHeight(root->left);
			updataHeight(root->right);
		}
	}
}

void create(Node* &root, int x){
		insert(root,x);
}

void BFS(Node* root){
	queue<Node* > q;
	root->rank = 1;
	int cnt = 1;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if (cnt != temp->rank){
			cnt++;
			printf("\n");
		}
		printf("%d ",temp->data);
	//	printf("因子是%d 层数是%d ",getBalanceFactor(temp),getHeight(root));
		if (temp->left != NULL){
			temp->left->rank = temp->rank + 1;
			q.push(temp->left);
		}
		if (temp->right != NULL){
			temp->right->rank = temp->rank + 1;
			q.push(temp->right);
		}
	}
	printf ("\n");

}
int main(){
	int n;
	Node* root = NULL;
	vector<int> v;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++){
		int x;
		scanf ("%d", &x);
		create(root,x);
	//	printf ("----------------\n");
		
	//	BFS(root);
	}
		
	printf("%d\n",root ->data);
	
	return 0;
}

