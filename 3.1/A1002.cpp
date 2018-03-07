#include <cstdio>

int main(){
	int k;
	double aPolynomial[10001] = {0};	//多项式

	for (int i = 0; i < 2; i++){
		scanf("%d",&k);
		for (int i = 0; i < k; i++){
			int exponent;
			double coefficient;
			scanf ("%d%lf",&exponent, &coefficient);
			aPolynomial[exponent] += coefficient;	//多项式最终结果
		}
	}

	int count = 0;						//一共有count组 非零项
	int markExponent[10001];			//提高速度 记录第n组指数
	double markCoefficient[10001];		//提高速度 记录第n组系数
	for (int i =0; i <= 1000; i++){
		if (aPolynomial[i] != 0) {
			markExponent[count] = i;
			markCoefficient[count] = aPolynomial[i];
			count++;
		}
	}
	
	printf("%d",count);
	for (int i = count-1;i >= 0; i--){
		printf(" %d %.1lf",markExponent[i],markCoefficient[i]);
	}

	return 0;
}
