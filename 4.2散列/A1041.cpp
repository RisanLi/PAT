#include <iostream>
using namespace std;

int main(){
	int arr1[100010] = {0};		//放值
	int arr2[100010] = {0};		//记录各个值出现的次数

	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d",&arr1[i]);
		arr2[arr1[i]]++;
	}

	int counter = 0;
	for (int i = 0; i < n; i++){
		if (arr2[arr1[i]] == 1){
			printf("%d\n",arr1[i]);
			return 0;
		}
		counter++;
	}
	if (counter == n){
		printf("None\n");
	}
	return 0;
}
