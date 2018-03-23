#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> array;
	for (int i = 0; i < 10; i++){
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; j++){
			array.push_back(i);
		}
	}
	sort(array.begin(),array.end());
	int count = 0;
	for (int& i : array){
		if (i != 0 && count==0){
			printf("%d",i);
			i = -1;
			count++;
		}
	}
	for (int i : array){
		if (i != -1){
			printf ("%d",i);
		}
	}

	printf ("\n");

	return 0;
}

