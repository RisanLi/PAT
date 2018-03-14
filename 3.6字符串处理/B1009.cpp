#include <cstdio>

int main(){
	char words[1000][80];
	int i = 0;
	while(scanf("%s",words[i++]) != EOF);	//当再次输入时候输入空 才会返回EOF 此时i已经比输入的多一个，在i++ 此刻多了 i比字符串数多2
	i -= 2;

	for (int j = i; j > 0; j--){
		printf("%s ",words[j]);
	}
	printf("%s",words[0]);
		

	return 0;
}
