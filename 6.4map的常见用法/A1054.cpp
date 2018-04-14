#include <cstdio>
#include <map>
using namespace std;

int main(){
	int col,row;
	scanf("%d%d", &col, &row);
	map<int,int> mp;
	for(int i = 0; i < col * row; i++){
		int x;
		scanf ("%d", &x);
		mp[x]++;	//此题无需初始化，一个不存在的key默认value初始化为0
					//一旦使用这个key 则保存在了 map当中
	}
	map<int,int>::iterator it = mp.begin();
	int max = -1, num;
	for(it; it != mp.end(); it++){
		if(it->second > max){
			num = it->first;
			max = it->second;
		}
	}

	printf ("%d\n",num);


	return 0;
}
