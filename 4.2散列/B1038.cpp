#include <cstdio>

const int MAX = 100010;
int score[MAX] = {};

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		int s;
		scanf("%d",&s);
		score[s]++;
	}
	scanf ("%d",&n);
	for (int i = 0; i < n; i++){
		int num;
		scanf ("%d",&num);
		if ( i != 0) printf(" ");
		printf("%d",score[num]);
	}
}
