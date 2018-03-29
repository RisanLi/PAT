#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	int a[100010];

	scanf ("%d%d",&n, &m);

	for (int i = 0; i < n; i++){
		scanf ("%d",&a[i]);
	}
	sort(a,a+n);
	bool flag = false;
	for (int i = 0; i < n; i++){
		int left = i + 1, right = n - 1, mid;
		while (left <= right){
		mid = (left + right) / 2;
			if (a[mid] == m -a[i]){
				break;
			}
			else if (a[mid] < m - a[i]){
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		if (left <= right){
			printf ("%d %d\n",a[i],a[mid]);
			flag = true;
			break;
		}
	}
	if (!flag){
		printf ("No Solution\n");
	}
}
