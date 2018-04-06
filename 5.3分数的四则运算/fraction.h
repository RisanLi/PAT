#include <cstdio>

long long gcd (long long a, long long b){
	//化简分数的时候要分子分母同除以最大公约数
	if (b == 0) return a;
	else return gcd(b, a%b);
}
struct Fraction{
	long long numeratior;	//分子　可取0, + , -
	long long denominatior;	//分母　只能为正整数
};

Fraction reduction(Fraction result){
	if (result.denominatior < 0){	//若分母＜0分子分母取反
		result.numeratior *= -1;
		result.denominatior *= -1;
	}

	if (result.numeratior == 0){	//规定:结果为0的分数 分子为0,分母为1
		result.denominatior = 1;
	}
	else{							//分子分母同时除以最大公约数化简
		long long gcdNumber =gcd(abs(result.numeratior), result.denominatior);
		result.denominatior /= gcdNumber;
		result.numeratior /= gcdNumber;
	}
	return result;
}

Fraction addFraction(Fraction f1, Fraction f2){
	Fraction result;
	result.numeratior = f1.numeratior * f2.denominatior + f2.numeratior * f1.denominatior;
	result.denominatior = f1.denominatior * f2.denominatior;

	return reduction(result);		//必须返回一个化简后的分数
}

Fraction minusFraction(Fraction f1, Fraction f2){
	Fraction result;
	/**
	 * 常规的分子分母操作
	 */
	return reduction(result);		//返回化简后的分数
}

Fraction multiFraction(Fraction f1, Fraction f2){
	/**
	 * 常规分子分母操作
	 */
	return reduction(result);
}

Fraction divideFraction(Fraction f1, Fraction f2){
	//常规操作
	//返回化简后的结果
}

void printResult(Fraction result){
	result = reduction(result);
	if (result.denominatior == 1){		//整数
		printf("%lld",result.numeratior);
	} else if (abs(result.numeratior) > result.denominatior){	//假分数
		printf ("%lld %lld/%lld",result.numeratior/result.denominatior, abs(result.numeratior) % result.denominatior, result.denominatior);
	} else {							//真分数
		printf("%lld/%lld",result.numeratior,result.denominatior);
	}
}
