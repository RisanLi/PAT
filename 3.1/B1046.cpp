#include <cstdio>

int main(){
	int aWin_count = 0, bWin_count = 0;		//甲赢的次数，乙赢的次数,甲乙同赢不算次数
	int n;									//一共的局数
	scanf("%d",&n);

	int aYelling, aPut, bYelling, bPut;		//甲喊的数字，甲出的数字，乙同理
	for (int i = 0; i < n; i++){
		scanf("%d%d%d%d",&aYelling, &aPut, &bYelling, &bPut);
		if (aYelling + bYelling == aPut && aYelling + bYelling != bPut)
			aWin_count++;
		else if (aYelling + bYelling != aPut && aYelling + bYelling == bPut)
			bWin_count++;
	}

	printf("%d %d\n",bWin_count,aWin_count);


}
