#include <cstdio>

int main(){
	long long A, B, Da, Db;
	long long Pa, Pb;
	scanf("%lld",&A);
	scanf("%lld",&Da);
	scanf("%lld",&B);
	scanf("%lld",&Db);

	Pa = 0;
	Pb = 0;

	while (A != 0){
		if (A % 10 == Da)
			Pa = 10 * Pa + Da;
		A /= 10;
	}
	
	while (B != 0){
		if (B % 10 == Db)
			Pb = 10 * Pb + Db;
		B /= 10;
	}

	printf("%lld\n",Pa+Pb);
    
	return 0;
}
