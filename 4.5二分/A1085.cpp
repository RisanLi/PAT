#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int n;

int binarySearch(int i, long long x){	//在区间[i+1,n-1]中寻找第一个大于ｘ
	if (a[n-1] <= x) return n;
	else {
	int left = i + 1, right = n - 1, mid;
	while (left < right){
		mid = (left + right) / 2;
		if (a[mid] > x){
			right = mid;
		}
		else
			left = mid + 1;
	}
		return left;
	}
}


int main(){
	int p;
	scanf ("%d%d",&n, &p);
	for (int i = 0; i < n; i++){
		scanf ("%d", &a[i]);
	}
	sort (a,a+n);
	int maxLength = 1;
	for (int i = 0; i < n ; i++){
		long long x = a[i] * p;
		int firstMore = binarySearch(i, x);
		maxLength = max(maxLength, firstMore - i);
	}

	printf("%d",maxLength);

}
