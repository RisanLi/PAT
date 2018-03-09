#include <cstdio>
#include <math.h>

int main(){
	int row, col;
	char charactor;

	scanf("%d %c",&row, &charactor);

	col = round(row/2.0);

	for(int i = 0; i < row; i++)
		printf("%c",charactor);
	printf("\n");
	for(int i = 0; i < col-2; i++){
		printf("%c",charactor);
		for(int i = 0; i < row-2; i++){
			printf(" ");
		}
		printf("%c\n",charactor);
	}
	for(int i = 0; i < row; i++)
		printf("%c",charactor);
	printf("\n");
	
	return 0;
}
