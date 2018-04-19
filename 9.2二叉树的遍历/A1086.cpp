#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
const int maxn = 50;
int pre[maxn];
int in[maxn];
vector<int> v;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* create(int preL, int preR, int inL, int inR){
	if (preL > preR){
		return NULL;
	}
	Node* node = new Node;
	node->data = pre[preL];
	int k;
	for (k = inL; k <= inR; k++){
		if (in[k] == node->data){
			break;
		}
	}

	int num = k - inL;
	node->left = create(preL + 1, preL + num, inL, k - 1);
	node->right = create(preL + num + 1, preR, k + 1, inR);
	return node;
}

int n;
int count = 0;
void postOrder(Node* root){
	if (root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
//	v.push_back(root->data);
	printf ("%d",root->data);
	count++;
	if (count < n) printf(" ");
}
int main(){
	int a = 0, b = 0, x;
	scanf ("%d", &n);
//	getchar();
	char str[maxn];
	stack<int> s;
	for (int i = 0; i < 2 * n; i++){
		scanf("%s",str);
		if (str[1] == 'o'){
			in[a++] = s.top();
			s.pop();
		}
		else{
                  	scanf("%d", &x);
			s.push(x);
			pre[b++] = x;
		}
	}
	Node* root = create(0, n-1, 0, n-1);
	postOrder(root);
//	int var = 0;
//	for (int i : v){
//		if (var++ != 0){
//			printf (" ");
//		}
//			printf("%d", i);
//	}
	return 0;

}

