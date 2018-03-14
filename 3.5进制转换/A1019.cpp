#include <cstdio>

int main(){
	int inDecimal, base;
	scanf ("%d%d",&inDecimal, &base);
	int rest[40],quotient = inDecimal;
	int i = 0;
	do{
		rest[i++] = quotient % base;
		quotient /= base;
	}while(quotient != 0);
	
	i--;
	bool flag = true;
	for(int j = i; j >= 0; j--){
		if(rest[j] != rest[i-j]) flag = false;
	}
	if (flag) printf("Yes\n");
	else printf("No\n");

	for(int j = i; j > 0; j--){
		printf("%d ",rest[j]);
	}
	printf("%d",rest[0]);

	return 0;
}
