/**
 * 借助B1028 人口普查问题的解决办法
 * 将时间换算成更好比较大小的方式
 * 不开更多的数组 只需要求得sign in最早的对象和sign out最晚的对象即可
 */

#include <cstdio>
struct Student{
	char ID[20];
	int inHour, inMin, inSec;	//sign in hh:mm:ss
	int outHour, outMin, outSec;	//sign out hh:mm:ss
};

int inTimeNumber(Student s){
	int num;
	num = s.inHour * 10000 + s.inMin * 100 + s.inSec;
	return num;
}

int outTimeNumber(Student s){
	return s.outHour * 10000 + s.outMin * 100 + s.outSec;
}

int main(){
	int n;	//输入n行
	scanf("%d", &n);
	Student inEarliest, outLatest;
	Student temp;
	int latest = 0, earliest = 24 * 10000 + 60 * 100 +60;
	for (int i = 0 ; i < n ; i++){
		scanf("%s %d:%d:%d %d:%d:%d",temp.ID,&temp.inHour,&temp.inMin,
				&temp.inSec, &temp.outHour, &temp.outMin, &temp.outSec);
		if(earliest >= inTimeNumber(temp)){
			inEarliest = temp;
			earliest = inTimeNumber(temp);
		} 
		if(latest <= outTimeNumber(temp)){
			outLatest = temp;
			latest = outTimeNumber(temp);
		}
	}
	
	printf("%s %s\n",inEarliest.ID,outLatest.ID);

	return 0;
}
