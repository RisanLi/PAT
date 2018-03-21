#include <cstdio>
#include <cstring>
#include <cctype>

int main(){
	char instr[100];
	char outstr[100];
	bool counter[1000];

	scanf ("%s%s",instr,outstr);
	for (size_t i = 0; i < strlen(outstr); i++){
		counter[tolower(outstr[i])] = true;
	}
	for(size_t i =0; i < strlen(instr); i++){
		if(!counter[tolower(instr[i])]){
			printf ("%c",toupper(instr[i]));
			counter[tolower(instr[i])] = true;
		}
	}

}
