#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1001000;
int prime[maxn],primeNum = 0;
bool p[maxn] = {0};

void primeTable(){
	for(int i = 2; i < maxn; i++){
		if (!p[i]){
			prime[primeNum++] = i;
			for (int j = i *2; j < maxn; j += i){
				p[j] = true;
			}
		}
	}
}

int main(){
	primeTable();
	int m,n,count = 0;
	scanf ("%d%d",&m,&n);
	for (int i = m -1; i < n; i++){
		printf("%d",prime[i]);
		count++;
		if (count % 10 == 0) printf("\n");
		else if (count < n - m+1){
			printf(" ");
		}
	}

	return 0;
}
