#include<cstdio>
int main(){
    long long a, b, da, db;
    scanf("%lld%lld%lld%lld", &a, &da, &b, &db);
    long long pa = 0, pb = 0;
    while(a != 0){      //枚举 a 的每一位
        if(a % 10 == da) pa = pa * 10 + da; //若当前位为 da，给 pa 增加一位 da
        a = a / 10; 
    }
    while(b != 0){      //枚举 b 的每一位
        if(b % 10 == db) pb = pb * 10 + db;
        b = b / 10; 
    }
    printf("%lld\n", pa + pb);
    return 0;
}
