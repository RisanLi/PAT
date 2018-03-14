#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char intSymbol,interger;
	char other[20000];
	int EPosition = 0;
	char expoSymbol;
	int exponent = 0;
	scanf("%c%c.%s",&intSymbol,&interger,other);
	for(size_t i = 0; i<strlen(other); i++){
		if(other[i] == 'E'){
			EPosition = i;
			expoSymbol = other[i+1];
			break;
		}
	}
	for (size_t i = EPosition+2; i < strlen(other);i++){
		exponent = exponent * 10 +other[i]-'0';
	}	
	if(intSymbol == '-'){
		cout<<intSymbol;
	}
	if (exponent == 0){
		cout<<interger<<".";
		for (int i = 0 ; i < EPosition; i++){
			cout<<other[i];
		}
	}
	else if(expoSymbol == '-'){
		cout<<"0.";
		for(int i =0; i < exponent-1; i++){
			cout<<"0";
		}
		cout<<interger;
		for (int i =0; i < EPosition;i++){
			cout<<other[i];
		}
	}
	else{					//指数符号为正
		cout<<interger;
		if(EPosition > exponent){	//带小数点的情况
			for (int i = 0; i < exponent;i++){
				cout<<other[i];
			}
			cout<<".";
			for(int i = exponent; i < EPosition; i++){
				cout<<other[i];
			}
		}
		else {						//不带小数点的情况
			for (int i = 0; i < EPosition; i++){
				cout<<other[i];
			}
			for (int i = 0; i < exponent - EPosition ;i++){
				cout<<"0";
			}
		}
	}
	return 0;
}
