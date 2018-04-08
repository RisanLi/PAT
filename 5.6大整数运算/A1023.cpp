#include <cstdio>
#include <cstring>
int main(){
	char str[22];
	int len;
	scanf ("%s",str);
	len = strlen(str);

	int str_int[22] = {0};
	int count[10] = {0};
	for (int i = 0; i < len; i++){
		str_int[i] = str[len-i-1] - '0';
		count[str_int[i]]++;
	}
	int carry = 0;
	for (int i = 0; i <= len; i++){
		int temp = str_int[i] * 2 % 10 + carry;
		carry = str_int[i] * 2 / 10;
		str_int[i] = temp;
	}
	if (str_int[len] != 0){
		len++;
	}
	for (int i = 0; i < len; i++){
		count[str_int[i]]--;
	}
	bool flag = true;
	for (int i = 0; i < 10; i++){
		if (count[i] != 0) flag = false;
	}
	if (flag) printf ("Yes\n");
	else printf ("No\n");
	for (int i = len-1; i >= 0; i--){
		printf("%d",str_int[i]);
	}
}
