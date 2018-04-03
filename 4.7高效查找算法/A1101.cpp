#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int n;
	int input[100010] = {0};
	int aheadMax[100010] = {0};
	int beforeMin[100010] = {0};
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++){
		scanf ("%d",&input[i]);
	}
	aheadMax[0] = -1999999999;
	aheadMax[1] = -1999999999;
	for (int i = 2; i <= n; i++){
		aheadMax[i] = max(aheadMax[i-1],input[i-1]);
	}
	beforeMin[n] = 1999999999;
	for (int i = n-1; i >=0; i--){
		beforeMin[i] = min(beforeMin[i+1],input[i+1]);
	}
	int ans = 0;
	int record[100010];
	for (int i = 1; i <= n; i++){
		if (input[i]>aheadMax[i] && input[i] < beforeMin[i]){
			record[ans++] = input[i];
		}
	}

	printf ("%d\n", ans);
	sort(record,record+ans);
	for (int i = 0; i < ans; i++){
		if (i != 0) printf(" ");
		printf("%d",record[i]);
	}
	printf("\n");
	return 0;
}
