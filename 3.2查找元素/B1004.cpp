#include <iostream>
#include <cstdio>
struct Student{
	char name[15];	//字符型数组要开的大一点！！！！
	char ID[15];
	int score;
};

int main(){
	int n;
	Student student[10000];
	std::cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%s %s %d",student[i].name,student[i].ID,&student[i].score);
	}

	int top = 0;
	int bottom = 0;
	

	for (int i = 1; i < n; i++){
		if (student[top].score < student[i].score){
			top = i;
		}
		if (student[bottom].score > student[i].score){
			bottom = i;
		}
	}
	
	printf("%s %s\n",student[top].name,student[top].ID);
	printf("%s %s\n",student[bottom].name,student[bottom].ID);

	return 0;
}
