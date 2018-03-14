#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int changAccount = 0;
	int changePassword = 0;
	char username[30], password[30];
	char recordUsername[1000][30],recordPassword[1000][30];
	int n;
	cin >> n;	
	for (int i = 0; i < n; i++){
		scanf("%s%s",username,password);
		for (int i = 0; i < strlen(password); i++){
			if (password[i] == '1'){ password[i] = '@'; changePassword++;}
			if (password[i] == '0'){ password[i] = '%'; changePassword++;}
			if (password[i] == 'l'){ password[i] = 'L'; changePassword++;}
			if (password[i] == 'O'){ password[i] = 'o'; changePassword++;}
		}
			if (changePassword != 0){
				strcpy(recordUsername[changAccount],username);
				strcpy(recordPassword[changAccount],password);
				changAccount++;
			}

			changePassword = 0;
	}
	if (changAccount != 0){
		cout << changAccount <<"\n";
		for (int i = 0; i < changAccount; i++){
			cout << recordUsername[i] << " " << recordPassword[i] <<"\n";
		}
	}
	else {
		if (n == 1)
			cout << "There is 1 account and no account is modified";
		else
			cout << "There are " << n <<" accounts and no account is modified";
	}
	
}
