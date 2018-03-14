#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char num[120];
	char pinyin[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

	cin>>num;
	int count = 0;
	for (int i =0; i < strlen(num); i++){
		count += (num[i]-'0');
	}

	if(count >=100)
		cout<<pinyin[count/100]<<" "<<pinyin[((count%100)-count%10)/10]<<" "<<pinyin[count % 10];
	else if(count >= 10)
		cout<<pinyin[(count - count % 10)/10]<<" "<<pinyin[count % 10];
	else
		cout<<pinyin[count];


}
