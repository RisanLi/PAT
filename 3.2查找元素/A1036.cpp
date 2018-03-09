#include <cstdio>
#include <string.h>

struct Student{
	char name[20];
	char ID[20];
	char gender;
	int grade;
};


int main(){
	Student hFemale;	//highest grade female
	Student lMale;		//lowest grade male
	Student temp;
	strcpy(hFemale.name,"Absent");
	strcpy(lMale.name,"Absent");
	int lowestGrade = 100, highestGrade = 0;

	int n;	//n lines

	scanf("%d", &n);
	for	(int i = 0; i < n; i++){
		scanf("%s %c %s %d", temp.name, &temp.gender, temp.ID, &temp.grade);
		if (temp.gender == 'M' && lowestGrade > temp.grade){
			lMale = temp;
			lowestGrade = temp.grade;
		}
		if (temp.gender == 'F' && highestGrade < temp.grade){
			hFemale = temp;
			highestGrade = temp.grade;
		}
	}

	if (!strcmp(hFemale.name,"Absent")){
		printf("Absent\n");
	} 
	else
		printf("%s %s\n",hFemale.name,hFemale.ID);
	if (!strcmp(lMale.name,"Absent"))
		printf("Absent\n");
	else
		printf("%s %s\n",lMale.name,lMale.ID);
	
	if (!strcmp(hFemale.name,"Absent") || !strcmp(lMale.name,"Absent"))
		printf("NA\n");
	else
		printf("%d\n",hFemale.grade - lMale.grade);
	return 0;
}
