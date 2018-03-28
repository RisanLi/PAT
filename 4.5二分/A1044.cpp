#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	int left;
	int right;
	int difference;	//a[right] - a[left-1] - m　的结果
}b[100010];

bool cmp(node a, node b){
	if (a.difference != b.difference) return a.difference < b.difference;
	else 
		return a.left < b.left;
}

int main(){
	int n,m;	//n代表数量,m代表支付的钱数
	scanf ("%d%d",&n, &m);
	int a[100010] = {0};
	for (int i = 1; i <= n; i++){
		int x;
		scanf ("%d",&x);
		a[i] = a[i-1] + x;
	}
	//for (int i = 1; i <= n; i++){
	//	printf ("a[%d] = %d\n",i,a[i]);
	//}
	int counter = 0;
	for (int i = 1; i <= n; i++){
		int left = i , right = n+1, mid;
		while (left < right){			//left == right的时候跳出
			mid = (left + right) / 2;
			if (a[mid] - a[i-1] >= m)
				right = mid;
			else
				left = mid + 1;
		}
		if (left == n+1) continue;//若left==right==n+1 说明不存在大于等于
		else {
			b[counter].left = i;
			b[counter].right = right;
			b[counter].difference = a[right] - a[i-1] - m;
			counter++;
		}
	}
	sort (b,b+counter,cmp);
	//for (int i = 0; i < counter; i++){
	//	printf("b[%d].difference = %d\n",i,b[i].difference);
	//}

	int standard = b[0].difference;
	for (int i = 0; i < counter; i++){
		if (b[i].difference == standard){
			printf("%d-%d\n",b[i].left, b[i].right);
		}
		else
			break;
	}

	return 0;
}
