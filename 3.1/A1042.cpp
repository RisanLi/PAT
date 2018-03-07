/**
 * 注意序号和纸牌号的关系
 * 另有该题的java实现版，更直接
 */


#include <cstdio>
const int N = 54;
char mp[5] = {'S','H','C','D','J'};
int start[N+1], end[N+1], order[N+1];
int main(){
	int K;
	scanf("%d",&K);
	for (int i = 1; i <= N; i++){
		start[i] = i;
	}
	for (int i = 1; i <= N; i++){
		scanf("%d",&order[i]);
	}
	for (int i = 0; i < K; i++){
		for (int j = 1; j <= N; j++){
			end[order[j]] = start[j];
		}
		for (int i = 1; i <= N; i++){
			start[i] = end[i];
		}
	}
	for (int i = 1; i <= N-1; i++){
		end[i]--;
		printf ("%c%d ", mp[end[i] / 13], end[i] % 13 + 1);
	}
	printf ("%c%d",mp[end[54] / 13],end[54] % 13 + 1);
}

