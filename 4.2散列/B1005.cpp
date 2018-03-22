#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a, int b){
	return a > b;
}

int main(){
	bool hashTable[1000] = {false};
	hashTable[1] = true;
	int queue[110];
	int n;
	vector<int> result;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> queue[i];
	}
	for (int i = 0; i < n; i++){
		int temp = queue[i];
		if (temp % 2 == 0){
			temp /= 2;
		}
		else{
			temp = (temp * 3 + 1) / 2;
		}		
		while (hashTable[temp] == false){
			hashTable[temp] = true;
			if (temp % 2 == 0){
				temp /= 2;
			}
			else{
				temp = (temp * 3 + 1) / 2;
			}
		}
	}

	for (int i = 0; i < n; i++){
		if (!hashTable[queue[i]])
			result.push_back(queue[i]);
	}
	sort (result.begin(), result.end(), cmp);
	for (int i = 0; i < result.size();i++){
		if (i != 0) cout <<" ";
		cout << result[i];
	}
	return 0;
}
