#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	scanf ("%d",&n);
	int sqr = (int) sqrt (n);
	int start = 0,pointer = 2, length = 0;
	while (pointer <= sqr){
		long long product = 1;
		int length_tem = 0;
		int start_tem;
		int recordPointer = pointer;	//记录头开始的位置
		if (n % pointer == 0){
			recordPointer = pointer;
			start_tem = pointer;
			length_tem++;
			product *= pointer;
			while(1){
				pointer++;
				product *= pointer;
				if (n % product != 0) break;
				length_tem++;
			}
			if (length_tem > length){
				length = length_tem;
				start = start_tem;
			}
		}
		pointer = recordPointer+1;
	}
	if (start == 0){
		printf("1\n%d\n",n);	
	}
	else{
		printf("%d\n",length);
		for (int i = 0; i < length; i++){
			printf("%d",start++);
			if (i < length -1){
				printf ("*");
			}
		}
	}
	return 0;
}
