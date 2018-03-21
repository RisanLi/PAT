#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
	int n;
	cin >>n;
	int all[10010] = {0};
	for (int i = 0; i < n; i++){
		int groupNum, memberNum, memberScore;
		scanf("%d-%d%d",&groupNum, &memberNum, &memberScore);
		all[groupNum] += memberScore;
	}
	int max = 0;
	int pos = 0;
	for (int i = 1; i < 10010; i++){
		if (max < all[i]){
			max = all[i];
			pos = i;
		}
	}
	cout << pos << " " << max;
}
