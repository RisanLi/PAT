#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
bool cmp (int a, int b){
	return a > b;
}

int main(){
	int arr[1000];
	map<int, int> rank;		//map<体重数，排名>
	vector<int> input;		
	int n, g;
	scanf ("%d%d", &n, &g);
	for (int i = 0; i < n; i++){
		int x;
		scanf ("%d", &x);
		input.push_back(x);	
	}
	for (int i = 0; i < n; i++){
		int x;
		scanf ("%d", &x);
		arr[i] = input[x];
	}
//	printf("input : ");
//	for(int i : input){
//		printf ("%d ",i);
//	}
//	printf("\narr : ");
//	for (int i = 0; i < n; i++){
//		printf ("%d ",arr[i]);
//	}
//	printf("\n");
	vector<int> vOriginal, vNew;
	vOriginal.insert(vOriginal.begin(), arr,arr+n);
	while (vOriginal.size() != 1){
		int i = 0;
		for(i = 0; i < (int)vOriginal.size() / g * g; i += g){
			sort(vOriginal.begin() + i, vOriginal.begin() + i + g, cmp);
			int maxInt = vOriginal[i];
//			printf ("%d ",vOriginal[i]);
			vNew.push_back(maxInt);
		}
//		printf ("\n");
		int rest = vOriginal.size() - vOriginal.size() / g * g;

		if (rest < g && rest > 0 ){
			sort(vOriginal.begin() + i, vOriginal.end(), cmp);
			vNew.push_back(vOriginal[i]);
		}
		int r = vNew.size();		//晋级数组的个数+1就是剩余数组的排名
		for (int i : vOriginal){
			rank[i] = r + 1;		
		}
//		printf("晋级数：");
//		for (int i : vNew){
//			printf ("%d ",i);
//		}
//		printf ("\n");
		vOriginal.clear();			//原数组清空，把晋级数组赋值原数组
		vOriginal.insert(vOriginal.begin(),vNew.begin(),vNew.end());
		vNew.clear();				//晋级数组清空为下次循环做准备
	}

	rank[vOriginal[0]] = 1;

	for (int i = 0; i < n; i++){
		if(i != 0) printf(" ");
		printf ("%d",rank[input[i]]);
	}
	printf ("\n");
	return 0;
}

