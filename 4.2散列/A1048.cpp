#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	int arr[100010];
	int exist[100010] = {0};
	int pair[10010];
	for (int i = 0; i < n; i++){
		scanf ("%d",&arr[i]);
		exist[arr[i]]++;
		pair[arr[i]] = m - arr[i];
	}
	sort(arr,arr+n);
	bool flag = false;
	for (int i = 0; i < n; i++){
		if (exist[pair[arr[i]]] && pair[arr[i]] != arr[i]){
			printf ("%d %d\n",arr[i],m-arr[i]);
			flag = true;
		}
		else if (exist[pair[arr[i]]] >= 2 && pair[arr[i]] == arr[i]){
			printf ("%d %d\n",arr[i],m-arr[i]);
			flag = true;
		}	
		if (flag) {
			break;
		}
	}
	if (!flag)
		printf ("No Solution\n");

}
