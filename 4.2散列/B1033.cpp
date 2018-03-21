#include <cstdio>
#include <cstring>
#include <iostream>
#include <cctype>

const int maxn = 100010;
bool hashTable[256];
char str[maxn];

int main(){
	
	memset(hashTable,true,sizeof(hashTable));	//初值为true表示所有键ok
	fgets(str,maxn,stdin);			//stdin键盘读入 失效键位
	int len = strlen(str);				
	for (int i = 0; i < len; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str[i] - 'A' + 'a';		// 把所有大写转换成小写
		}
		hashTable[(int)str[i]] = false;
	}
	fgets(str,maxn,stdin);
	len = strlen(str);
	for (int i = 0; i < len; i++){
		if (str[i]>= 'A' && str[i] <= 'Z'){
			int low = str[i] - 'A' + 'a';
			if (hashTable[low] && hashTable[(int)'+']){
				printf("%c",str[i]);
			}
		}else if (hashTable[str[i]])
			printf("%c",str[i]);
	}
	printf("\n");

}
