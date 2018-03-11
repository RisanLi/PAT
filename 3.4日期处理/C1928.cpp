/**
 * 本题思路 以19130703 和 20180310 来举例子
 * 首先 从19130101 到 19130703 的总天数 d1
 * 再算 从20180101 到 20180310 的总天数 d2
 * 最后算 1913年到2017年总天数 			d3
 * 
 * 最后结果就是 d3 + d2 - d1 + 1；
 *
 * 将每个闰年和平年每个月的总天数列举出来 加快运算
 */ 




#include <cstdio>

bool isLeapYear(int y){
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}


int main(){
	//month数组 第一列为闰年的该月日期数，第二列为平年的该月日期数
	int month[13][2] = {{0,0}
						,{31,31}	// January
						,{28,29}	// Feb
						,{31,31}	// March
						,{30,30}	// April
						,{31,31}	// May
						,{30,30}	// June
						,{31,31}	// July
						,{31,31}	// Aug
						,{30,30}	// Sept
						,{31,31}	// Oct
						,{30,30}	// Nov
						,{31,31}};	// Dec
	int day1, day2;
	scanf("%d%d",&day1,&day2);

	int startYear , startMonth, startDay;
	int endYear, endMonth, endDay;

	startYear = day1 / 10000;
	startDay = day1 % 100;
	startMonth = (day1 % 10000 - startDay) / 100;

	endYear = day2 / 10000;
	endDay = day2 % 100;
	endMonth = (day2 % 10000 - endDay) / 100;

	int result = 0;
	// 先求年份差带来的日期数
	for(int i = startYear; i < endYear; i++){
		if (isLeapYear(i))	result += 366;
		else result += 365;
	}

	int leap;
	if (isLeapYear(startYear)) leap = 0;
	else leap = 1;
	// 求 起始年1月1日到 起始日期的天数
	for (int i = 1; i < startMonth; i++){
		result -= month[i][leap];
	}
	result -= startDay;

	if (isLeapYear(endYear)) leap = 0;
	else leap = 1;
	// 求 结束年1月1日 到结束日期的天数
	for (int i = 1; i < endMonth; i++){
		result += month[i][leap];
	}
	result += endDay;
	result++;

	printf("%d",result);
	return 0;
}
