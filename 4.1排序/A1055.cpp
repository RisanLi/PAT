/**
 * 如果存在超时的情况
 * 那么 就是在两层嵌套循环的时候 数量过多导致
 * 解决办法就是 ： 由于num题目已知 <= 100
 * 开足够多的Person类数组 把相同财富值的人 将在一个数组
 * 防止因为同一财富的人超过100 而那些超越100的人 不可能被输出
 */
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Person{
	char name[10];
	int age;
	int netWorths;
};

bool cmp(Person a, Person b){
	if (a.netWorths != b.netWorths) return a.netWorths > b.netWorths;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name,b.name) < 0;
}

int main(){
	int n,k;
	scanf("%d%d", &n, &k);
	vector<Person> vec;
	for (int i = 0; i < n; i++){
		Person temp;
		scanf("%s%d%d",temp.name, &temp.age, &temp.netWorths);
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end(),cmp);

	int num , minAge ,maxAge;
	for (int j = 1; j <= k; j++){
		scanf ("%d %d %d",&num, &minAge, &maxAge);
		printf ("Case #%d:\n",j);
		int counter= 0;
		for (Person i :vec){
			if (counter == num ) break;
			if (i.age >= minAge && i.age <= maxAge){
				printf("%s %d %d\n",i.name,i.age,i.netWorths);
				counter++;
			}
		}
		if (counter == 0) printf ("None\n");
	}
}
