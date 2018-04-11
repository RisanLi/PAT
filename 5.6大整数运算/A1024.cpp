#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 15;
struct Bign{
	int str[maxn];
	int len;
	Bign(){
		memset(str,0,sizeof(str));
		len = 0;
	}
};

bool isPalindromic(Bign s){
	int str[maxn];
	for(int i = 0; i < s.len; i++){
		str[i] = s.str[i];
	}
	int len = s.len;
	bool flag = true;
	for(int i = 0; i <= len/2 - 1; i++){
		if (str[i] != str[len-i-1]){
			flag = false;
			break;
		}
	}	
	return flag;
}

Bign reverseAdd(Bign s){
	int str1[maxn] = {0};
	int str1_len = s.len;
	for(int i = 0; i < s.len; i++){
		str1[i] = s.str[i] + s.str[s.len-i-1];
	}
	int carry = 0;
	for(int i = 0; i <= s.len; i++){
		str1[i] += carry;
		carry = str1[i] / 10;
		str1[i] = str1[i] % 10;
	}
	if (str1[str1_len] != 0){
		str1_len++;
	}
	Bign t;
	for (int i = 0; i < str1_len; i++){
		t.str[i] = str1[i];
	}
	t.len = str1_len;
	return t;
}

int main(){
	char str[maxn];
	int k;
	scanf("%s%d",str,&k);
	Bign b;
	for (int i = 0; i < strlen(str); i++){
		b.str[i] = str[i] - '0';
	}
	b.len = strlen(str);
	
	int cnt = 0;
	for (int i = 0; i < k; i++){
		if (isPalindromic(b)) break;
		b = reverseAdd(b);
		cnt++;
	}	
	for (int i = 0; i < b.len; i++){
		printf("%d",b.str[b.len-i-1]);
	}
	printf("\n%d\n",cnt);
	
	
	return 0;
}
