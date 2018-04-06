/**
 * 采用埃式筛法
 * Sieve of Eratosthenes
 */

#include <cstdio>
#include <cmath>
using namespace std;
int prime[10010]={0},primeNum = 0;
bool p[10010] ={0};		//p[i] == false 代表素数

void primeTable(int max){
	for(int i = 2; i <= max; i++){
		if (!p[i]){
			prime[primeNum++]  = i;
			for (int j = i + i; j <= max; j += i){
				p[j] = true; 		//是i的倍数的都为合数
			}
		}
	}
}

int binarySearch(int x){
	int left = 0, right = primeNum, mid;
	while(left <= right){
		mid = (left + right) / 2;
		if (prime[mid] == x) return mid;
		else if (prime[mid] < x){
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return left;
}

int main(){
	int start, end;
	scanf ("%d%d", &start, &end);
	primeTable(end);	//构造2~end 的质数表
	for(int i = 0; i < primeNum; i++){
		printf("%d ",prime[i]);
	}
	printf ("\n");
	//二分查找到start在质数表中的位置
	int pos = binarySearch(start);
	
	printf ("起始位置为 %d\n",pos);
	while(prime[pos] <= end && pos < primeNum){
		printf("%d",prime[pos]);
		if (++pos < primeNum)
			printf(" ");
	}
	
	return 0;
}
