#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int x){
	if (x == 1) return false;
	else{
		int sqr = (int) sqrt (1.0 * x);
		for (int i = 2; i <= sqr; i++){
			if (x % i == 0) return false;
		}
	}
	return true;
}

int main(){
	int tSize, n;
	const int maxn = 10010;
	bool table[maxn] = {0};
	scanf ("%d%d", &tSize, &n);
	while(!isPrime(tSize)){
		tSize++;
	}
	//printf ("tSize = %d\n",tSize);
	for (int i = 0; i < n; i++){
		int key , pos;
		scanf ("%d",&key);
		pos = key % tSize;
	//	printf ("pos is : %d\n",pos);
		if (!table[pos]){
			table[pos] = true;
			printf("%d",pos);
			if (i != n-1)
				printf (" ");
		} else {
			bool flag = true;	//表示在table中存在空余位置
			for(int j = 1; j < n; j++){
				pos = (key + j * j) % tSize;
				if (!table[pos]){
					table[pos] = true;
					flag = false;
					break;
				}
			}
			if (flag){
				printf("-");
				if ( i != n-1){
					printf (" ");
				}
			} else{
				printf ("%d",pos);
				if ( i != n-1){
					printf (" ");
				}
			}
		}
	}
	
	return 0;
}

