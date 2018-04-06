#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

struct Fraction{
	long long numerator;
	long long demoninator;
};

long long gcd(long long a, long long b){
	if (b == 0) return a;
	else return gcd(b,a%b);
}

Fraction reduction(Fraction result){
	if (result.demoninator < 0){
		result.demoninator *= -1;
		result.numerator *= -1;
	}

	if (result.numerator == 0){
		result.demoninator = 1;
	} else {
		long long gcdNumber = gcd (abs(result.numerator),result.demoninator);
		result.numerator /= gcdNumber;
		result.demoninator /= gcdNumber;
	}
	return result;
}

Fraction addFraction(Fraction f1, Fraction f2){
	Fraction result;
	result.numerator = f1.numerator * f2.demoninator + f1.demoninator * f2.numerator;
	result.demoninator = f1.demoninator * f2.demoninator;
	
	return reduction(result);
}

Fraction minusFraction(Fraction f1, Fraction f2){
	Fraction result;
	result.numerator = f1.numerator * f2.demoninator - f1.demoninator * f2.numerator;
	result.demoninator = f1.demoninator * f2.demoninator;
	
	return reduction(result);
}

Fraction multiFraction(Fraction f1, Fraction f2){
	Fraction result;
	result.numerator = f1.numerator * f2.numerator;
	result.demoninator = f1.demoninator * f2.demoninator;
	
	return reduction(result);
}

Fraction divideFraction(Fraction f1, Fraction f2){
	Fraction result;
	result.numerator = f1.numerator * f2.demoninator;
	result.demoninator = f1.demoninator * f2.numerator;
	
	return reduction(result);
}

void show(Fraction r){
	if (r.demoninator == 1){	//整数
		if (r.numerator < 0){
			printf ("(%lld)",r.numerator);
		}
		else {
			printf ("%lld",r.numerator);
		}
	} else if (abs(r.numerator) > r.demoninator){	//假分数
		if (r.numerator < 0) printf ("(");
		printf("%lld %lld/%lld",r.numerator/r.demoninator,abs(r.numerator)%r.demoninator,r.demoninator);
		if (r.numerator < 0) printf (")");
	} else {										//真分数
		if (r.numerator < 0) printf ("(");
		printf("%lld/%lld",r.numerator%r.demoninator,r.demoninator);
		if (r.numerator < 0) printf (")");
	}
}

int main(){
	Fraction f1, f2;
	scanf("%lld",&f1.numerator);getchar();
	scanf("%lld",&f1.demoninator);
	scanf("%lld",&f2.numerator);getchar();
	scanf("%lld",&f2.demoninator);

	f1 = reduction(f1);
	f2 = reduction(f2);
	char symbol[] = {'+','-','*','/'};
	if (f2.numerator != 0){
		Fraction result[4];
		result[0] = addFraction(f1,f2);
		result[1] = minusFraction(f1,f2);
		result[2] = multiFraction(f1,f2);
		result[3] = divideFraction(f1,f2);
		for (int i = 0; i < 4; i++){
			show(f1); cout << " " << symbol[i] << " ";
			show(f2); cout << " = ";
			show(result[i]); cout << "\n";
		}
	} else {
		for(int i = 0; i < 2; i++){
			show(f1); cout << " " << symbol[i];
			cout << " 0 = "; show(f1); cout << endl;
		}
		show(f1); cout << " * 0 = 0\n";
		show(f1); cout << " / 0 = Inf\n";
	}

	return 0;
}
