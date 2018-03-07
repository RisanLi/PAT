/**
 * @param :coincident 系数，power 指数
 * @param :count 输入的第n组数据，每个系数和指数为一组
 */

#include <cstdio>

int main(){
	int coincident, power;	
	int count = 1;
	while (scanf("%d%d",&coincident, &power) != EOF){
		if (power == 0 ){
			if (count == 1)	printf("0 0");		//当待求导函数为常函数
			else continue;						//待求导函数为非常函数 且有指数为0的项时，不需要任何输出
		}
		else {
			if(count == 1)						//待求函数为非常函数 第一组输出的时候打头输出
				printf("%d %d", coincident * power, power-1);
			else								//其他组输出为空一格输出
				printf(" %d %d",coincident * power, power-1);
		}

		count++;
	}
	return 0;
	
}
