/**
 * 局部贪心的思想
 * 如果在有效距离内
 * 　存在目标站的价格＜当前站的价格
 * 				　那么加到目标站恰好油量耗尽的油
 * 	不存在目标站的价格　<当前站的价格
 * 				那么找到有效范围内　价格最低的　在当前站把油加满，然后开到价格最低的站
 * 以上循环
 */				



#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Station{
	double price;
	double distance;
};

bool cmp(Station a, Station b){
	return a.distance < b.distance;
}
bool cmpByPrice(Station a, Station b){
	return a.price < b.price;
}

int main(){
	double cMax, D, Davg;	//cMax 油箱大小，Ｄ距离，Davg　油耗，ｎ加油站数量
	int n;
	vector<Station> gasStation;
	scanf ("%lf%lf%lf%d",&cMax, &D, &Davg, &n);
	double effectDis = cMax * Davg;
	for (int i = 0; i < n; i++){
		Station temp;
		scanf ("%lf%lf",&temp.price, &temp.distance);
		gasStation.push_back(temp);
	}
	//按照距离排序
	sort(gasStation.begin(),gasStation.end(),cmp);
	if (gasStation.begin()->distance != 0){
		printf ("The maximum travel distance = 0.00");
		return 0;
	}
	//将终点设置为单价为零的地方　为保证它在有效范围内最低。
	Station temp;
	temp.price = 0;
	temp.distance = D;
	gasStation.push_back(temp);

	vector<Station>::iterator currentStation,forwardStation;
	currentStation = gasStation.begin();
	forwardStation = currentStation + 1;
	double currentOil = 0;
	double expense = 0;

	while(currentStation != gasStation.end()-1){	//当前位置不能为终点	
		bool exist = false;	//假设不能再有效范围内找到最近的比当前便宜的加油站
		while (forwardStation->distance - currentStation->distance <= effectDis){
			if (forwardStation->price < currentStation->price){	//看能否找到
				exist = true;	
				break;
			}
			forwardStation++;
		}
		if (forwardStation->distance - currentStation->distance > effectDis) 
			if(forwardStation == currentStation +1){{
				printf ("The maximum travel distance = %.2lf",currentStation->distance+effectDis);
				return 0;
			}
			
		}
		if (exist){		//找到了的话
			double needOil = (forwardStation->distance - currentStation->distance) / Davg;//从当前到目标之间需要的油量
			if (currentOil < needOil){	//当前油量不够
				expense += (needOil - currentOil) * currentStation->price; //加到刚刚够，这样到达时油量为０
				currentOil = 0;
			}
			else {						//当前油量多了
				currentOil -= needOil;	//不用花费，直接花掉
			}
			currentStation = forwardStation;//到达目标加油站
		}
		else {	//没有找到　，此时forwordStation 指向有效距离外第一个加油站
			vector<Station>::iterator it = currentStation + 1, cheapest = it;
			while (it != forwardStation){	//寻找从当前位置到forwardStation 之间最便宜的加油站　区间为左闭右开
				if (cheapest->price > it->price){
					cheapest = it;
				}
				it++;
			}
			forwardStation = cheapest;   //把最便宜的加油站作为目标站点
			expense += (cMax - currentOil) * currentStation->price;
			currentOil = cMax;
			currentOil -= (forwardStation->distance - currentStation->distance) / Davg;
			currentStation = forwardStation;
		}
	}
	if (forwardStation == gasStation.end()){
		printf ("The maximum travel distance = %.2lf",currentStation->distance+effectDis);
		return 0;
	}
	printf ("%.2lf\n",expense);
	return 0;
}
