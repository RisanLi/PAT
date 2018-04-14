#include <iostream>
#include <map>
using namespace std;

bool isOK(char x){
	if (x >= 'a' && x<= 'z')
		return true;
	else if (x >= 'A' && x <= 'Z')
		return true;
	else if (x >= '0' && x <= '9')
		return true;
	else 
		return	false;
}

bool isCap(char x){
	if (x >= 'A' && x <= 'Z')
		return true;
	else 
		return false;
}

int main (){
	string s;
	getline(cin,s);
	map<string, int> count;
	string temp;
	int first = 0, last = 0;
	while (!isOK(s[first])){	//使一个元素为有效元素
		first++;
		last++;
	}
	while (isOK(s[first])){
		temp = "";
		while(isOK(s[last]) && last < s.size()){
			if (isCap(s[last])){
				s[last] = s[last] - 'A' + 'a'; 
			}
			temp += s[last];
			last++;
		}
		while (!isOK(s[last]) && last < s.size()){
			last++;
		}
		first = last;
		count[temp]++;
	}
	map<string, int>::iterator it = count.begin();
	int max = -1;
	string word;
	for(it; it != count.end(); it++){
		if (it->second > max){
			max = it->second;
			word = it->first;
		}
	}
	cout << word << " " << max << endl;

	return 0;
}
