/**
 * 因为本题结果只有两位
 * 因此不必采取 除模取余法
 * 第一位 为 a/radix
 * 第二位 为 a%radix
 */

#include <cstdio>


int main(){
	char radix[13] ={'0'
					,'1'
					,'2'
					,'3'
					,'4'
					,'5'
					,'6'
					,'7'
					,'8'
					,'9'
					,'A'
					,'B'
					,'C'};
	int a , b, c;
	scanf("%d%d%d",&a,&b,&c);

	printf("#%c%c",radix[a/13],radix[a%13]);
	printf("%c%c",radix[b/13],radix[b%13]);
	printf("%c%c",radix[c/13],radix[c%13]); 


	return 0;
}
