#include <cstdio>
char sort(int b, int c, int j){
	if (b >= c){
		if (b >= j) return 'B';
		else return 'J';
	} else {
		if (c >= j) return 'C';
		else return 'J';
	}
}

int main(){
	int N;		//一共的局数
	char aPut;		//甲的手势
	char bPut;		//乙的手势
	int aWinCount = 0, bWinCount = 0;		//甲，乙赢得次数
	int aEqualCount = 0, bEqualCount = 0;	//甲，乙平的次数
	int aLoseCount = 0, bLoseCount = 0;		//甲，乙输的次数
	int aJ = 0, aC = 0, aB = 0;				//甲获胜中剪子锤子和布的次数
	int bJ = 0, bC = 0, bB = 0;
	scanf("%d",&N);
	
	for (int i = 0; i < N; i++){
		getchar();
		scanf("%c %c",&aPut,&bPut);
		if(aPut == bPut){
			aEqualCount++;
			bEqualCount++;
		} else if ((aPut == 'J' && bPut == 'B') 
					|| (aPut == 'C' && bPut == 'J')
					|| (aPut == 'B' && bPut == 'C')){
			if (aPut == 'J') aJ++;
			else if (aPut == 'C') aC++;
			else aB++;

			aWinCount++;
			bLoseCount++;
		} else {
			if (bPut == 'J') bJ++;
			else if (bPut == 'C') bC++;
			else bB++;
			bWinCount++;
			aLoseCount++;
		}
	}

	printf("%d %d %d\n",aWinCount, aEqualCount, aLoseCount);
	printf("%d %d %d\n",bWinCount, bEqualCount, bLoseCount);
	
	printf("%c %c\n",sort(aB,aC,aJ),sort(bB,bC,bJ));

	
}
