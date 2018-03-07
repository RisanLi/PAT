#include <cstdio>
#include <ctime>
#define CLK_TCK 100 //已知每秒打100点数

int main(){
	int C1, C2;
 	scanf("%d%d",&C1,&C2);//时钟打点数

	int ans = C2 - C1;						//4577850

	if (ans % 100 >= 50){
		ans = ans / CLK_TCK + 1; 
	}
	else
		ans /= CLK_TCK; //总秒数
	
 	int hour = ans / 3600; 					//1271
	int minute = (ans - hour * 3600) / 60;	//37
	int second = ans - hour * 3600 -minute * 60; //
	printf("%02d:%02d:%02d",hour,minute,second);
	
	return 0;
}
