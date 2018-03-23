#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
struct Mooncake{
	double stock;	//库存
	double price;	//单价

};
bool cmp(Mooncake a, Mooncake b){
	return a.price > b.price;
}

int main(){
	int n, k;
	scanf ("%d%d",&n, &k);
	double stock[1010];
	double tPrice[1010];
	vector<Mooncake> mooncake;
	for (int i = 0; i < n; i++){
		scanf ("%lf",&stock[i]);
	}
	for (int i = 0; i < n; i++){
		scanf ("%lf",&tPrice[i]);
	}
	for (int i = 0; i < n; i++){
		Mooncake temp;
		temp.stock = stock[i];
		temp.price = tPrice[i] / stock[i];
		mooncake.push_back(temp);
	}
	sort(mooncake.begin(),mooncake.end(),cmp);
	double profit = 0;
	for (Mooncake i : mooncake){
		if (k == 0) break;
		if (k >= i.stock){
			profit += i.price * i.stock;
			k -= i.stock;
			continue;
		}
		if (k < i.stock){
			profit += k * i.price;
			k = 0;
		}
	}
	printf ("%.2lf\n",profit);

	return 0;
}
