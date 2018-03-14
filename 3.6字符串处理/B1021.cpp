#include <cstdio>
#include <cstring>

int main(){
	char input[1010];
	int count[10]={0};
	scanf("%s",input);

	int length = strlen(input);
	for(int i =0; i < length; i++){
		count[input[i]-'0']++;
	}
	for(int i = 0; i < 10; i++){
		if(count[i] != 0){
			printf("%d:%d\n",i,count[i]);
		}
	}

	return 0;
}
