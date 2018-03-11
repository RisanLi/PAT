#include <cstdio>
#include <string.h>

int main (){
	char string[100];

	scanf ("%s",string);
	int length = strlen(string);
	
	int n1 = (length + 2) / 3;
	int n2 = length + 2 - n1 * 2;
	for (int i = 0; i < n1 -1; i++){
		printf("%c",string[i]);
		
		for (int i = 0; i < n2 - 2; i++){
			printf(" ");
		}
		printf("%c\n",string[length-i-1]);
	}
	for (int i = 0; i < n2; i++){
		printf("%c",string[n1+i-1]);
	}


}
