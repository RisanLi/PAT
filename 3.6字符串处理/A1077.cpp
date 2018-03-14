/**
 * 如果有getline 等吸收一行的时候
 * 其前方一定要有getchar将 空格或者换行符吸收掉
 */


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string str[100];
	char charactor;
	string kuchiguse = "";
	int min = 1000;		//输入的最短字符串的字符数
	int n;
	cin >> n;
	getchar();			//吸收换行符
	for (int i = 0; i < n; i++){
		getline(cin,str[i]);
		reverse(str[i].begin(),str[i].end());
		min = (min>str[i].length())?str[i].length():min;
	}
	charactor = str[0][0];
	for (int i = 1; i < n; i++){
		if (charactor != str[i][0]){
			cout << "nai\n";
			return 0;
		}
	}
	for (int i = 0; i < min; i++){
		charactor = str[0][i];
		bool isSame = true;
		for (int j = 0; j < n; j++){
			if(str[j][i] != charactor){
				isSame = false;
				break;
			}
		}
		if (isSame)
			kuchiguse += charactor;
		else
			break;
	}

	reverse(kuchiguse.begin(),kuchiguse.end());
	cout << kuchiguse;

	
}
