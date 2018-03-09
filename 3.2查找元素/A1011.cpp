#include <cstdio>

int main(){
	double oddsWin, oddsTie, oddsLose;
	char result[3] = {'W','T','L'};
	double maxOdds[3];
	int pointer[3];

	for (int i = 0; i < 3; i++){
		scanf("%lf%lf%lf",&oddsWin, &oddsTie, &oddsLose);
		if (oddsWin >= oddsTie){
			if ( oddsWin >= oddsLose){
				maxOdds[i] = oddsWin;
				pointer[i] = 0;
			}
			else{
				maxOdds[i] = oddsLose;
				pointer[i] = 2;
			}
		}
		else {
			if (oddsTie >= oddsLose){
				maxOdds[i] = oddsTie;
				pointer[i] = 1;
			}
			else{
				maxOdds[i] = oddsLose;
				pointer[i] = 2;
			}
		}
	}

	printf("%c %c %c",result[pointer[0]],result[pointer[1]],result[pointer[2]]);
	printf(" %.2lf\n",(maxOdds[0]*maxOdds[1]*maxOdds[2]*0.65-1)*2);

	return 0;
}
