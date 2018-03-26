#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
	return a + b < b + a;
}

string str[10010];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> str[i];
	}
	sort(str,str+n,cmp);
	string ans;
	for (int i = 0; i < n; i++){
		ans += str[i];
	}
	while (ans[0] == '0'){
		ans.erase(ans.begin());
	}
	if (ans == "") cout << 0;
	else
		cout << ans;
	return 0;
}
