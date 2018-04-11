#include <iostream>
#include <string>
#include <iostream>
using namespace std;

struct Snumber{
	string str;
	int pow;
};
int n;

int judgeNumber(string s){
	int cnt = 0;	//假定s没有0或者小数点.
	for(int i = 0; i < s.size(); i++){
		if (s[i] == '0' || s[i] == '.') cnt++;
	}
	if (cnt == s.size()) return -1;		//-1代表 该数为0

	//对s头部的0进行消减
	while(s[0] == '0'){
		s.erase(s.begin());
	}
	if(s[0] == '.') return 0;		//0代表 该数＜1
	else return 1;					//1代表 该数>=1
}

Snumber modify(string s, int type){
	Snumber temp;
	switch(type){
		case -1:{
			temp.str = "0.";
			for(int j = 0; j < n; j++){
				temp.str += "0";
			}
			temp.pow = 0;
			break;
		}
		case 0:{
			size_t dotPos = s.find(".");
			int pow = 0;
			int i;
			for(i = dotPos+1; i < s.size(); i++){
				if (s[i] != '0'){
					pow = i - dotPos - 1;
					pow *= -1;
					break;
				}
			}
			temp.str = "0." + s.substr(i,s.size());
			if (temp.str.size() < n+2){
				for(int j = 0; j < n+2-temp.str.size(); j++){
					temp.str += "0";
				}
			} else {
				temp.str = temp.str.substr(0,n+2);
			}
			temp.pow = pow;
			break;
		}
		case 1:{
			while(s[0]=='0'){
				s.erase(s.begin());
			}
			int i = 0;
			while(s[i] != '.'){
				i++;
				if (i >= s.size()) break;
			}
			if (i == s.size()){
				temp.str = "0." +s;
				temp.pow = s.size();
			}
			else {
				s.erase(s.begin()+i);
				temp.str = "0." + s;
				temp.pow = i;
			}
			if (temp.str.size() < n+2){
				for(int j = 0; j < n+2-temp.str.size(); j++){
					temp.str += "0";
				}
			} else {
				temp.str = temp.str.substr(0,n+2);
			}
			
	  }
	}
	return temp;
}
int main(){
	string str1, str2;
	cin >> n >> str1 >> str2;
	int str1_type = judgeNumber(str1);
	int str2_type = judgeNumber(str2);
//		cout << "str1 type = " << str1_type << endl;
//		cout << "str2_type = " << str2_type << endl;
	Snumber a, b;
	a = modify(str1,str1_type);
	b = modify(str2,str2_type);
//		cout << "a.str" << a.str << " a.pow " << a.pow << endl;
//		cout << "b.str" << b.str << " b.pow " << b.pow << endl;

	if (a.str == b.str && a.pow == b.pow){
		printf("YES ");
		printf("%s*10^%d",a.str.c_str(),a.pow);
	}
	else{
		printf("NO ");
		printf("%s*10^%d %s*10^%d",a.str.c_str(),a.pow,b.str.c_str(),b.pow);
	}
	return 0;
}
