#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct node {
	int position_A;
	int left_P;
	int right_T;
};


int main(){
	string str;
	cin >> str;
	int leftNumberP[100010] = {0};
	int rightNumberT[100010] = {0};
	vector<int> aPosition;
	int length = str.size();
	if (str[0] == 'P'){
		leftNumberP[0] = 1;
	}
	if (str[0] == 'A')
		aPosition.push_back(0);
	if (str[length - 1] == 'T')
		rightNumberT[length-1] = 1;

	for (size_t i = 1; i < length; i++){
		if (str[i] == 'P'){
			leftNumberP[i] = leftNumberP[i-1] + 1;
		}	
		else{
			leftNumberP[i] = leftNumberP[i-1];
		}
		if (str[i] == 'A'){
			aPosition.push_back(i);
		}
	}


	for (int i = length -2; i >= 0; i--){
		if (str[i] == 'T'){
			rightNumberT[i] = rightNumberT[i+1] + 1; 
		}
		else {
			rightNumberT[i] = rightNumberT[i+1];
		}
	}
	long long  ans = 0;
	for (int i : aPosition){
		ans += (long long)leftNumberP[i] * rightNumberT[i];
	}
	cout << ans % 1000000007 << endl;

	return 0;
}
