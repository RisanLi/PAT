/**
 * sum值可能会等于0 因此要特殊输出
 */


#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
  	int sum = a + b;
	char str[1000010];
	if (sum < 0){
		cout << "-";
		sum *= -1;
	}
	int comma = 0;
	int count = 0;
	char string[1000010];
	if(sum == 0){
		cout<< 0;
	}else{

		while (sum != 0){
			if (comma % 3 == 0 && comma != 0){
				string[count++] = ',';
			}
			string[count++] = sum % 10 + '0';
			sum /= 10;
			comma++;
		}
		for (int i = count -1;i >= 0; i--){
			cout<<string[i];
		}
	}
}
