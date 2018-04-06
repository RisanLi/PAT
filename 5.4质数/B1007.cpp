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
	int n;
	scanf ("%d",&n);
	int i = 0;
	int count = 0;
	while(prime[i+1] <= n){
		if (prime[i+1] - prime[i] == 2){
			count++;
		}
		i++;
	}
	printf ("%d",count);
}
