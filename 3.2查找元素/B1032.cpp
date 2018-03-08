#include <cstdio>
#include<algorithm>

int main(){
	int n;	//输入的行数
	scanf("%d",&n);

	int info[100001] = {0};
	int school, score;
	for (int i =0; i < n; i++){
		scanf ("%d%d", &school, &score);
		info[school] += score;
	}
	int maxSchool = 0;
	int totalScore = info[maxSchool];
	for (int i = 1; i < 100001; i++){
		if (info[maxSchool] < info[i]){
			maxSchool = i;
			totalScore = info[i];
		}
	}

	printf("%d %d\n", maxSchool, totalScore);

	return 0;
}
