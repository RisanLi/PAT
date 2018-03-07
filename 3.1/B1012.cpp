/**
 * 本程序结果不太正确有两个 测试点错误 
 * 具体程序请看书p14-15
*/

#include <cstdio>

int main(){
	int array[1100];
	int N;			//输入的正整数个数
	
	scanf("%d",&N);
	for (int i = 1; i <= N; i++){
		scanf("%d",&array[i]);
	}
	
	int A1 = 0, A1_count= 0, A2 = 0, A2_count = 1, A3 = 0, A3_count = 0, A5 = 0, A5_count = 0;
	double A4 = 0.0;
	int A4_count = 0;

	for(int i = 1; i <= N; i++){
		if (array[i] % 10 == 0){
			A1_count++;
			A1 += array[i];
		}
		if (array[i] % 5 == 1){
			if (A2_count % 2 == 1){
				A2 += array[i];
				A2_count++;
			}
			else{
				A2 -= array[i];
				A2_count++;
			}
		}
		if (array[i] % 5 == 2){
			A3++;
			A3_count++;
		}
		if (array[i] % 5 == 3){
			A4 += array[i];
			A4_count ++;
		}
				
		if (array[i] % 5 == 4 ){
			if(A5 < array[i])
				A5 = array[i];
			A5_count++;
		}
	}

	A4 = A4 / A4_count;

	if (A1_count == 0)
		printf("N ");
	else 
		printf("%d ",A1);
	if (A2_count == 0)
		printf("N ");
	else
		printf("%d ",A2);
	if (A3_count == 0)
		printf("N ");
	else 
		printf("%d ",A3); 
	if (A4_count == 0) 
		printf("N "); 
	else 
		printf("%.1f ",A4);
	if (A5_count == 0)
		printf("N\n");
	else 
		printf("%d\n",A5);
}
