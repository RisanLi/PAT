#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

map<int,string> MAR_1, MAR_2;
map<string,int> EARTH;
void init(){
	MAR_1[0] = "";
	MAR_1[1] = "jan";
	MAR_1[2] = "feb";
	MAR_1[3] = "mar";
	MAR_1[4] = "apr";
	MAR_1[5] = "may";
	MAR_1[6] = "jun";
	MAR_1[7] = "jly";
	MAR_1[8] = "aug";
	MAR_1[9] = "sep";
	MAR_1[10] = "oct";
	MAR_1[11] = "nov";
	MAR_1[12] = "dec";
	MAR_2[1] = "tam";
	MAR_2[2] = "hel";
	MAR_2[3] = "maa";
	MAR_2[4] = "huh";
	MAR_2[5] = "tou";
	MAR_2[6] = "kes";
	MAR_2[7] = "hei";
	MAR_2[8] = "elo";
	MAR_2[9] = "syy";
	MAR_2[10] = "lok";
	MAR_2[11] = "mer";
	MAR_2[12] = "jou";
	EARTH["jan"] = 1;
	EARTH["tam"] = 13;
	EARTH["feb"] = 2;
	EARTH["hel"] = 2*13;
	EARTH["mar"] = 3;
	EARTH["maa"] = 39;
	EARTH["apr"] = 4;
	EARTH["huh"] = 4*13;
	EARTH["may"] = 5;
	EARTH["tou"] = 5*13;
	EARTH["jun"] = 6;
	EARTH["kes"] = 6*13;
	EARTH["jly"] = 7;
	EARTH["hei"] = 7*13;
	EARTH["aug"] = 8;
	EARTH["elo"] = 8*13;
	EARTH["sep"] = 9;
	EARTH["syy"] = 9*13;
	EARTH["oct"] = 10;
	EARTH["lok"] = 130;
	EARTH["nov"] = 11;
	EARTH["mer"] = 11*13;
	EARTH["dec"] = 12;
	EARTH["jou"] = 12*13;
	
}

void earthToMars(string str){
	vector<int> v;
//	printf("str.c_str 为 %s\n",str.c_str());
	int x = atoi(str.c_str());
//	cout << "转化为数字为 " << x << endl;
	while (x != 0){
		v.push_back(x%13);
		x /= 13;
	}
	reverse(v.begin(),v.end());
//	while (v.size() != 0){
//		if (v.size() == 1){
//			if (v[0] != 0){
//				cout << MAR_1[v[0]] << endl;
//				v.erase(v.begin());
//			}
//			else
//				v.erase(v.begin());
//		} else {
//			cout << MAR_2[v[0]] << " ";
//			v.erase(v.begin());
//		}
//	}
	for(int i = 0; i < v.size()-1; i++){
		cout << MAR_2[v[i]];
		if (i != v.size()-2)
			cout << " ";
	}
	if (v[v.size()-1] != 0 && v.size()>1){
		cout << " " <<MAR_1[v[v.size()-1]] << endl;
	}
	else if (v.size() == 1 && v[v.size()-1] != 0){
		cout <<MAR_1[v[v.size()-1]] << endl;
	}
	else cout << endl;
}

void marsToEarth(string str){
	int sum = 0;
	while (str.size()>3){
		sum =sum * 13 + EARTH[str.substr(0,3)];
//		cout << "sum 当前值" << sum << endl;
		str.erase(0,4);
//		cout << "剪裁过后string" << str << endl;
	}
	sum += EARTH[str];
	cout << sum << endl;
}

int main(){
	init();
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++){
		string str;
		getline(cin,str);
		if(str[0] > '0' && str[0] <= '9'){
			earthToMars(str);
		} else if (str == "0"){
			cout << "tret\n";
		} else {
			marsToEarth(str);
		}
	}
	return 0;
}

