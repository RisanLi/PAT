#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Record{
	string name;
	int month, day, hour, min;
	bool status;
	int expense; // expense 仅限 status 为 0 的对象使用记录消费
};

bool cmp(Record a, Record b){
	if(a.name.compare(b.name) != 0) return a.name < b.name;
	else if (a.month != b.month) return a.month < b.month;
	else if (a.day != b.day) return a.day < b.day;
	else if (a.hour != b.hour) return a.hour < b.hour;
	else return a.min < b.min;
}

double calculateCharge(vector<Record>::iterator a,vector<Record>::iterator b,double charge[]){
	printf("%02d:%02d:%02d ", a->day, a->hour, a->min);
	printf("%02d:%02d:%02d ", b->day, b->hour, b->min);
	int startDay = a->day, startHour = a->hour, startMin = a->min;
	int endDay = b->day, endHour = b->hour, endMin = b->min;
	int totalMin = 0;
	double totalCharge = 0;
	int aDayCharge = 0;
	int minusStartDay = 0;
	int plusEndDay = 0;
	for (int i = 0; i < 24; i++){		//一天最多消费
		aDayCharge += charge[i] * 60;
	}

	for (int i = 0; i < startHour; i++){	//开始那天未消费
		minusStartDay += charge[i] * 60;
		totalMin += 60;
	}
	minusStartDay +=  charge[startHour] * startMin;
	totalMin += startMin;

	minusStartDay = aDayCharge - minusStartDay;
	totalMin = 24*60 - totalMin;

	for (int i = 0; i < endHour; i++){
		plusEndDay += charge[i] * 60;
		totalMin += 60;
	}
	plusEndDay += charge[endHour] * endMin;
	totalMin += endMin;
	totalCharge = minusStartDay + plusEndDay;
	for (int i = startDay ; i < endDay-1; i++){
		totalMin += 24 * 60;
		totalCharge += aDayCharge;
	}
	if (startDay == endDay){
		totalMin -= 24*60;
		totalCharge -= aDayCharge;
	}
	printf("%d $%.2lf\n",totalMin,totalCharge/100);
	return totalCharge/100;
}
int main (){
	int n;
	vector<Record> rec;
	vector<Record> finalRecord;
	double charge[24];				//从charge[x] 代表从 x~x+1 时段收费
	for (int i = 0; i < 24; i++){
		cin >> charge[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		Record r;
		string status;
		cin >> r.name;
		scanf("%d:%d:%d:%d",&r.month, &r.day, &r.hour, &r.min);
		cin >> status;
		if (status.compare("on-line") == 0){
			r.status = true;
		}
		else r.status = false;
		rec.push_back(r);
	}
	sort(rec.begin(),rec.end(),cmp);
	vector<Record>::iterator it = rec.begin();
	while((it+1) != rec.end()){
		if (it->name.compare((it+1)->name) == 0){
			if (it->status == true && (it+1)->status == false){
				finalRecord.push_back(*it);
				finalRecord.push_back(*(it+1));
			}
		}
		it++;
	}
	string name = finalRecord.begin()->name;
	cout << name;
	printf(" %02d\n",finalRecord.begin()->month);
	double sum = 0;
	for (vector<Record>::iterator i = finalRecord.begin(); i != finalRecord.end();i++){
		if (i->status != false) continue;
		if (name.compare(i->name) != 0){
			printf("Total amount: $%.2lf\n",sum);
			name = i->name;
			cout << name << " ";
			printf("%02d\n",i->month);
			sum = 0;					//换个人总费用清零
		} 
		sum += calculateCharge(i-1,i,charge);
	}
	printf("Total amount: $%.2lf\n",sum);

	return 0;
}
