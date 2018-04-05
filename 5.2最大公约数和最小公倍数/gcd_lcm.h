/** 最大公约数Greatest Common Divisor
 *  a,b的最大公约数 简写为gcd(a,b)
 *
 *  最小公倍数Lowest Common Multiple
 *  a,b的最小公倍数 简写为lcm(a,b)
 */
#include <cstdio>

int gcd(int a, int b){
	if (b == 0) return a;
	else
		return gcd(b, a % b);
}

//最小公倍数公式为 a*b/gcd(a,b)
//防止a*b溢出　故采用一下方式
int lcm(int a, int b){
	return a / gcd (a,b) * b;
}
