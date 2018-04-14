#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main(){
	int stackSize, inputSize, n;
	scanf ("%d%d%d", &stackSize, &inputSize, &n);
	for (int x = 0; x < n; x++){
	stack<int> sta;
	queue<int> que;
		for (int i = 1; i <= inputSize; i++){
			int y;
			scanf ("%d",&y);
			que.push(y);
		}
		int j = 1;
		for (j; j <= que.front(); j++){
			sta.push(j);
		}
		j--;
		while (j <= inputSize && sta.size() <= stackSize &&!que.empty()){
			while (!sta.empty() && !que.empty() && sta.top() == que.front()){
				sta.pop();
				que.pop();
			}
			if (j+1 > inputSize) break;
			sta.push(++j);
		}
		if (sta.empty())
			printf ("YES\n");
		else
			printf ("NO\n");
//		while (!sta.empty()){
//			printf ("%d",sta.top());
//			sta.pop();
//		}
		
	}
	return 0;
}
