#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int gcd(int a, int b){
	if (b == 0) return a;
	else 
		return gcd(b, a%b);
}
struct Fraction{
	int numerator;	//分子可正可负
	int denominator;//分母必须为正整数
};

Fraction reduction(Fraction a){
	Fraction result;
	result.numerator = a.numerator;
	result.denominator = a.denominator;
	if (result.numerator == 0){
		result.denominator = 1;
		return result;
	}
	if (result.denominator == 0){
		result.numerator *= -1;
		result.denominator *= -1;
	}
	int gcdNumber = gcd (abs(result.numerator),abs(result.denominator));
	result.numerator /= gcdNumber;
	result.denominator /= gcdNumber;
	return result;
}

Fraction addFraction(Fraction a, Fraction b){
	Fraction result;
	result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	result.denominator = a.denominator * b.denominator;
	result = reduction(result);
	return result;
}


int main(){
	int n;
	cin >> n;
	vector<Fraction> fracVec;
	for (int i = 0; i < n; i++){
		Fraction temp;
		cin >> temp.numerator;
		getchar();
		cin >> temp.denominator;
		fracVec.push_back(temp);
	}
	Fraction sum;
	sum.numerator = 0;
	sum.denominator = 1;
	for(Fraction i : fracVec){
	//	cout << i.numerator << " " << i.denominator << endl;
		sum = addFraction(sum,i);
	//	cout << sum.numerator << " " << sum.denominator << endl;
	}
	//如果有假分数输出整数部分和分数部分
	if (sum.numerator / sum.denominator){
		cout << sum.numerator / sum.denominator;
		if (sum.numerator % sum.denominator != 0){
			cout << " ";
			cout << abs(sum.numerator) % sum.denominator;
			cout << "/" << sum.denominator << endl;
		}
		else cout << endl;
	}
	else{
		if (sum.numerator != 0)
			cout << sum.numerator << "/" << sum.denominator << endl;
		else
			cout << "0" <<endl;
	}
	
}
