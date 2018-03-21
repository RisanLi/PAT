#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	char str1[1010];
	char str2[1010];
	int hashTable[128] = {0};
	bool less = false;

	scanf("%s%s", str1, str2);
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);
	for (int i = 0; i < str1Len; i++){
		hashTable[(int)str2[i]]++;
	}
	for (int i = 0; i < str1Len; i++){
		hashTable[(int)str1[i]]--;
	}
	for (int i = 0; i < str2Len; i++){
		if (hashTable[(int)str2[i]] > 0) 
			less = true;
	}
	if (less){
		sort(str2,str2 + str2Len);
		int lack = 0;
		lack += hashTable[str2[0]];
		for (int i = 1; i < str2Len; i++){
			if (str2[i]==str2[i-1]) continue;
			else 
				if (hashTable[str2[i]]>0)
					lack += hashTable[str2[i]];
		}
		printf("No %d\n",lack);
	}
	else
		printf ("Yes %d\n",str1Len - str2Len);

	return 0;
}
