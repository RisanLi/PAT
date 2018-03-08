/**
 *
 * 本题关键在于 当不存在最老或者最年轻的时候不输出
 * 当同时不存在最老和最年轻的时候 只输出0，其后没有空格
 */ 




// 自己的解法：缺点浪费空间，不巧妙

#include <cstdio>
#include <string.h>

struct Person{
	char name[15];
	int year;
	int month;
	int day;
};

bool isLegal(Person p){
	if(p.year == 1814 && p.month == 9 && p.day >= 6)
		return true;
	else if (p.year == 1814 && p.month > 9) return true;
	else if (p.year > 1814 && p.year < 2014) return true;
	else if (p.year == 2014 && p.month == 9 && p.day <= 6) return true;
	else if (p.year == 2014 && p.month < 9) return true;
	else
		return false;
	
}

bool isElder(Person eldest,Person temp){
	if (eldest.year < temp.year) return true;
	else if (eldest.year == temp.year && eldest.month < temp.month)
		return true;
	else if (eldest.year == temp.year && eldest.month == temp.month 
			&& eldest.day <temp.day) 
		return true;
	else return false;
}

bool isYounger(Person youngest,Person temp){
	if(youngest.year > temp.year) return true;
	else if(youngest.year == temp.year 
			&& youngest.month > temp.month) return true;
	else if (youngest.year == temp.year 
			&& youngest.month == temp.month
			&& youngest.day > temp.day) return true;
	else 
		return false;

	
}


int main() {
	int n;			//输入的个数
	Person person[100001];
	scanf ("%d",&n);
	for (int i = 2;i <= n+1; i++){			//防止第0个人的出生日期不合法
		scanf ("%s %d/%d/%d",person[i].name,
				&person[i].year, &person[i].month, &person[i].day);
	}
	//strcpy(person[0].name,"illegal");
	person[0].year = 1814;
	person[0].month = 9;
	person[0].day = 6;

	person[1].year = 2014;
	person[1].month = 9;
	person[1].day =6;

	int legal = 0;
	int eldest = 1;
	int youngest = 0;
	for (int i = 2; i <=n+1; i++){
		if (isLegal(person[i])){
			legal++;
			if (!isElder(person[eldest],person[i])){
				eldest = i;
			}
	
			if(!isYounger(person[youngest],person[i])){
				youngest = i;
			}
		}
	}
	if (legal != 0)
		printf("%d %s %s",legal,person[eldest].name,person[youngest].name);
	else 
		printf("%d",legal);
	return 0;
}


