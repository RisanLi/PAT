#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 1010;

int CBT[maxn];
int array[maxn];
int n, cnt = 0;
void inOrder(int root){
	if (root > n){
		return;
	}
	inOrder(2 * root);
	CBT[root] = array[cnt++];
	inOrder(2 * root + 1);
}

int main(){
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		int x;
		scanf ("%d", &x);
		array[i] = 	x;
	}
	sort(array,array+n);
	inOrder(1);
	for (int i = 1; i <= n; i++){
		if (i != 1){
			printf (" ");
		}
		printf ("%d", CBT[i]);
	}


	return 0;
}
