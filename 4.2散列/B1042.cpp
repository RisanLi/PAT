#include <cstdio>
#include <cctype>
#include <cstring>

int main(){
	char str[1010];
	int hashTable[130] = {0};
	fgets(str,1010,stdin);
	int len = strlen(str);
	
	for (int i = 0; i < len; i++){
		int low = tolower(str[i]);
		hashTable[low]++;
	}
	int maxNum = hashTable['a'];
	char pos = 'a';
	for (int i = 'a'; i <= 'z'; i++){
		if (maxNum < hashTable [i]){
			maxNum = hashTable[i];
			pos = i;
		}
	}
	printf ("%c %d\n",pos,maxNum);

	return 0;
}
