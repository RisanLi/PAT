#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	char str[110];
	int n;
	scanf ("%d", &n);
	getchar();
	for (int i = 0; i < n; i++){
		fgets(str,110,stdin);
		int length = strlen(str) - 1;	//str中被fgets读入了换行符
//		cout << "length = " << length << endl;
		int pPosition, tPosition;
		for (int j = 0; j < length; j++){
			if (str[j] == 'P') pPosition = j;
			else if (str[j] == 'T') tPosition = j;
			else if (str[j] == 'A'){}
			else {
				tPosition = 1;
				pPosition = 100;
				break;
			}
		}
//		cout << "pPosition = " << pPosition << endl;
//		cout << "tPosition = " << tPosition << endl;

		int aNum = pPosition - 0;
		int bNum = tPosition - pPosition - 1;
		int cNum = length - 1 - tPosition;
		
//		cout << aNum << " " << bNum << " " << cNum << endl;

		if (aNum * bNum == cNum && bNum != 0){
			printf ("YES\n");
		} else {
			printf ("NO\n");
		}
	}
	return 0;
		
}
