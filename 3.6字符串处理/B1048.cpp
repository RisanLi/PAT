#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	char AInverse[105], BInverse[105];
	scanf("%s %s",AInverse,BInverse);
	char A[105],B[105];
	memset(A,'0',105);			//字符数组初始化
	memset(B,'0',105);
	int ALength = strlen(AInverse);
	int BLength = strlen(BInverse);

	for (int i = 0; i < ALength; i++){
		A[i] = AInverse[ALength - i - 1];
	}
	for (int i = 0; i < BLength; i++){
		B[i] = BInverse[BLength - i - 1]; 
	}
	int length = 0;
	char outArray[105];
	int max = ALength > BLength ? ALength:BLength;
	//从0位开始 因此数字中奇数位 在数组中为偶数数位
	for (int i = 0 ; i < max; i++){		
		if (i % 2 == 0){
			int base = A[i] + B[i] - '0' - '0';
			base %= 13;
			if (base < 10) outArray[i] = '0' + base;
			else if (base == 10) outArray[i] = 'J';
			else if (base == 11) outArray[i] = 'Q';
			else outArray[i] = 'K';
		}
		else {
			int base = B[i] - A[i];
			outArray[i] = (base + 10) % 10 + '0';
		}
		length++;
	}
	for (int i = length -1; i >= 0; i--){
		cout<<outArray[i];
	}


}
