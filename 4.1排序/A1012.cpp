#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

struct Student{
	int ID;
	int a,c,m,e;		//代表各科成绩
	int rank[4];		//1代表c的学科排名，2代表m，3代表e ,0代表a
};
int point[1000100];//point[x] 代表id为x的学生 在stu相对头指针的位移

bool cmp(int a, int b){
	return a > b;
}

int getRank(int list[],int score){
	// 已知list为从大到小的排序
	// score一定在数组list当中
	int i = 0;
	for (i; score != list[i]; i++);
	return i+1;
}

int getHighRank(int rank[]){
	int j = 0;
	for (int i = 1; i < 4; i++){
		if (rank[j] > rank[i])
			j = i;
	}
	return j;
}

int main (){
	int n,m;
	int cList[2000] = {-1};
	int mList[2000] = {-1};
	int eList[2000] = {-1};
	int aList[2000] = {-1};

	memset(point,-1,sizeof(point));
	cin >> n >> m;
	vector<Student> stu;

	for (int i = 0; i < n; i++){
		Student temp;
		scanf("%d %d %d %d",&temp.ID, &temp.c, &temp.m, &temp.e);
		temp.a = (temp.c + temp.m + temp.e) / 3;
		cList[i] = temp.c;
		mList[i] = temp.m;
		eList[i] = temp.e;
		aList[i] = temp.a;
		point[temp.ID] = i;
		stu.push_back(temp);
	}
	sort(cList,cList+n,cmp);
	sort(mList,mList+n,cmp);
	sort(eList,eList+n,cmp);
	sort(aList,aList+n,cmp);
	for (int i = 0; i < m; i++){
		int id;
		scanf("%d",&id);
		if (point[id] == -1){
			printf("N/A\n");
			continue;
		}
		vector<Student>::iterator it = stu.begin();
		it = it + point[id];
		it->rank[0] = getRank(aList,it->a);
		it->rank[1] = getRank(cList,it->c);
		it->rank[2] = getRank(mList,it->m);
		it->rank[3] = getRank(eList,it->e);
		char bestCourse;
		int highRank = getHighRank(it->rank);
		if (highRank == 0) bestCourse= 'A';
		else if (highRank == 1) bestCourse = 'C';
		else if (highRank == 2) bestCourse = 'M';
		else bestCourse = 'E';
		printf("%d %c\n",it->rank[highRank],bestCourse);
	}
	
	return 0;
}
