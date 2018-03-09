#include <cstdio>
#include <math.h>
int main(){
	int lines = 1;		// 一共lines行
	int total = 1;
	int m;
	char c;

	scanf("%d %c",&m,&c);
/*超时原因**********************************************
	while(true){
		if (total <= m && m < (total+(lines*2-1)*2)) break;
		else {
			lines++;
			total += (lines * 2 -1) * 2;
		}
	}
*******************************************************/
	lines =floor(sqrt((m+1)/2));
	total = lines * lines * 2 -1;	

	//上半漏斗
	for (int i = lines; i >= 1; i--){
		for(int j = lines; j > i; j--){				//打印空格
			printf(" ");
		}
		for(int j = 1; j < 2 * i -1; j++){		//打印*
			printf("%c",c);
		}
		printf("%c\n",c);							//打印最后一个*换行
	}

	//下半漏斗
	for (int i = 2; i <= lines; i++){
		for (int j = lines; j > i; j--){
			printf(" ");
		}
		for(int j = 1; j <2 *i -1; j++){
			printf("%c",c);
		}
		printf("%c\n",c);
	}	
	printf("%d\n",m-total);
	return 0;
}
