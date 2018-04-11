#include <cstdio>
#include <set>
using namespace std;

int main(){
	int n;
	scanf ("%d", &n);
	set<int> st[55];
	for (int i = 1; i <= n; i++){
		int m;
		scanf ("%d", &m);
		for (int j = 0; j < m; j++){
			int x;
			scanf ("%d", &x);
			st[i].insert(x);
		}
	}
	int k;
	scanf ("%d", &k);
	for (int i = 0; i < k; i++){
		int p1,p2;
		scanf ("%d%d",&p1, &p2);
		set<int> temp;
		int common = 0, distinct = 0;
		for (int i : st[p1]){
			if (st[p2].find(i) != st[p2].end()){
				common++;
			}
		}

		distinct = (st[p1].size() - common) + (st[p2].size() - common)+ common;
		printf("%.1lf%%\n",(double)common/distinct * 100);
	}
	return 0;
}
