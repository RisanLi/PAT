#include <iostream>
using namespace std;

int main (){
	string str;
	cin >> str;
	if (str[0] == '-'){
		str.erase(str.begin());
		cout <<"Fu ";
	}
	Chin[10][10] ={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int length = str.length();
	if (length >= 9){
		string p1 = str.substr(0,1);
		string p2 = str.substr(1,4);
		string p3 = str.substr(5,4);
		cout <<Chin[p1[0]-'0']<<" Yi";
		if (!(p2[0]==p2[1]==p2[2]==p2[3]==p3[0]==p3[1]==p3[2]==p3[3]=='0')){
			bool hasZero1 = false;
			if (!(p2[0]==p2[1]==p2[2]==p2[3])){
				bool hasZero2 = false;
				for (int i = 0;i < 4;i++){
					if(str[i]=='0'){
						if(!hasZero2){
							cout << " ling";
							hasZero2 = true;
						}
					}
					else {
						cout<<" "<<Chin[p2[i]-'0'];
					}
				}

				cout <<" Wan";
			}
			else{
				cout << " ling";
			}
			for(int i = 0; i < 4; i++){
				if(p3[i]=='0'){
					if(!hasZero1){
						cout << " ling";
						hasZero1 = true;
					}
				}
				else{
					cout <<" "<<Chin[p3[i]-'0'];
				}
			}
			
		}
	}
	else if (length >= 5){
		string p1;
		string p2;
		for(int i = str.length()-4;i < str.length();i++){
			p2 += str[i];
		}
		for (int i =0; i < str.length()-4;i++){
			p1+=str[i];
		}
		if ()

	}

}
