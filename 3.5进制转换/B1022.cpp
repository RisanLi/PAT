#include <cstdio>

int main (){
	int A , B;
	int D;

	scanf("%d%d%d",&A, &B, &D);

	int sum = A + B;
	
	int rest[40];
	int i = 0;
	int quotient = sum;
	do {
		rest[i++] = quotient % D;
		quotient = quotient / D;
		
	}while (quotient != 0);
	i--;
	for (int j = i; j >= 0; j--){
		printf("%d",rest[j]);
	}

	return 0;
}
