#include <cstdio>
#include <cmath>
using namespace std;

int prime[1000100],primeNum = 0;
bool p[1000100] = {0};
void primeTable(int x){
	int sqr = (int) sqrt (1.0 * x);
	for (int i = 2; i < 1000000; i++){
		if (p[i] == false){
			prime[primeNum++] = i;
			for (int j = i + i; j < 1000000; j += i){
				p[j] = true;
			}
		}
	}
}

struct Factor{
	int fac;
	int cnt;
};

int main(){
	Factor factor[10];
	int facNum = 0;
	int n;
	scanf ("%d",&n);
	if (n == 1){
		printf ("1=1");
		return 0;
	}
	primeTable(n);
	int fi = n;
	int sqr = (int) sqrt(1.0 * n);
	for (int i = 0; prime[i] <= sqr ; i++){
		if (n % prime[i] == 0){
			factor[facNum].fac = prime[i];
			factor[facNum].cnt = 0;
			while(n % prime[i] == 0){
				factor[facNum].cnt++;
				n /= prime[i];			//因为除以的都为因子,因此n最终为1
			}
			facNum++;
		}
	}
	if (n != 1){
		factor[facNum].fac = n;
		factor[facNum].cnt = 1;
		facNum++;
	}
	printf("%d=",fi);
	for (int i = 0; i < facNum; i++){
		printf("%d",factor[i].fac);
		if(factor[i].cnt > 1){
			printf ("^%d",factor[i].cnt);
		}
		if (i+1 < facNum)
			printf("*");
	}

	return 0;
}
