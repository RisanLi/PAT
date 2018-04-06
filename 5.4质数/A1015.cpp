#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1001000;
int prime[maxn],primeNum = 0;
bool p[maxn] = {0};

bool isPrime(int x){
	if (x == 1) return false;
	for (int i = 2; i <= (int)sqrt(1.0*x); i++){
		if (x % i == 0) return false;
	}
	return true;
}
int main(){
	int n,d;
	while(scanf("%d",&n)!=EOF){
		if (n < 0) break;
		scanf("%d",&d);
		if(!isPrime(n)){
			printf("No\n");
			continue;
		}
		vector<int> r;
		while(n != 0){
			r.push_back(n%d);
			n /= d;
		}
		reverse(r.begin(),r.end());
		int sum = 0, base = 1;
		for(int i : r){
			sum += i * base;
			base *= d;
		}
		printf ("reverse is : %d",sum);
		if (isPrime(sum)){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
