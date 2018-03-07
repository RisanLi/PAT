#include <cstdio>

int main(){
	int N;
	long long M;
	int A[110];

	scanf("%d%lld",&N, &M);
	for(int i = 0; i < N; i++){
		scanf("%d",&A[i]);
	}

	M = M % N;		//防止

	for (int i = N-M; i < N ; i++){
		printf("%d ",A[i]);
	}
	
	for (int i = 0; i< N-M-1; i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[N-M-1]);
	return 0;
}
