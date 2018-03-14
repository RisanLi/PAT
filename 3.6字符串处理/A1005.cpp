#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	char str[110];
	cin >> str;
	char Eng[10][10] = {"zero"
		,"one","two","three","four","five","six","seven","eight","nine"};

	int length = strlen(str);
	int sum = 0;
	for (int i = 0; i < length; i++){
		sum += str[i] - '0';
	}
	sprintf(str,"%d",sum);
	length = strlen(str);

	for (int i = 0; i < length-1; i++){
		cout << Eng[str[i]-'0']<<" ";
	}
	cout << Eng[str[length-1]-'0'];

}
