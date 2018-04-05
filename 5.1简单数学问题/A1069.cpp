#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

bool cmpByIncrease (char a, char b){
	return a < b;
}
bool cmpByDecrease (char a, char b){
	return a > b;
}

int main(){
	char input[10];
	fgets(input,10,stdin);
	int result = atoi(input);
	char minus[10],minused[10];
	int int_minus,int_minused;
	while (result != 0){
		sprintf(minus,"%04d",result);
		sort(minus,minus+4,cmpByDecrease);
		sprintf(minused,"%04d",result);
		sort(minused,minused+4,cmpByIncrease);
		int_minus = atoi(minus);
		int_minused = atoi(minused);
		result = int_minus - int_minused;
		printf("%04d - %04d = %04d\n",int_minus,int_minused,result);
		if (result == 6174) break;
	}

	return 0;
}
