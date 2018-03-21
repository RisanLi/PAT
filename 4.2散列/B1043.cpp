#include <iostream>
using namespace std;

int main(){
	string str;
	cin >> str;
	int hashTable[128] = {0};

	for (char i : str){
		if (i == 'P' || i == 'A' || i == 'T' || i == 'e' || i == 's' || i == 't')
			hashTable[i]++;
	}
	for (int i = 0; i < str.size(); i++){
		if(hashTable['P'] != 0){
			cout << "P";
			hashTable['P']--;
		}
		if (hashTable['A'] != 0){
			cout << "A";
			hashTable['A']--;
		}
		if (hashTable['T'] != 0){
			cout << 'T';
			hashTable['T']--;
		}
		if (hashTable['e'] != 0){
			cout << "e";
			hashTable['e']--;
		}
		if (hashTable['s'] != 0){
			cout << "s";
			hashTable['s']--;
		}
		if (hashTable['t'] != 0){
			cout << "t";
			hashTable['t']--;
		}
	}

}
