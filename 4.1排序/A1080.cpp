#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Student{
	int id;
	int GE, GI;
	double finalGrade;
	int choice[5];
	int rank;
};

bool cmp(Student a, Student b){
	if (a.finalGrade != b.finalGrade) return a.finalGrade > b.finalGrade;
	else  return a.GE > b.GE;
}

bool cmp_2(Student a, Student b){
	return a.id < b.id;
}
int main(){
	int n, m, k;		//n代表申请人数，m代表学校数量，k代表志愿数量
						//所有数列均从0开始 到n-1
	int max[100];		//每个学校预录取的人数
	vector<Student> admission[100];//每个学校实际录取的名单
	vector<Student> stuList;	//学生名单
	scanf ("%d %d %d",&n, &m, &k);
	for (int i = 0; i < m; i++){
		scanf ("%d",&max[i]);
	}
	for (int i = 0; i < n; i++){
		Student temp;
		scanf("%d%d",&temp.GE, &temp.GI);
		for (int j = 0; j < k; j++){
			scanf("%d",&temp.choice[j]);
		}
		temp.id = i;
		temp.finalGrade = (temp.GE + temp.GI) / 2.0;
		stuList.push_back(temp);
	}
	if (n ==0){
		for (int i = 0; i < m; i++){
			printf("\n");
		}
		return 0;
	}
	//已经排除stuList为空的可能
	sort(stuList.begin(),stuList.end(),cmp);
	
	vector<Student>::iterator it = stuList.begin();
	it->rank = 1;
	it++;
	int rank = 1;
	for (it; it != stuList.end();it++){
		rank++;
		if (it->finalGrade == (it-1)->finalGrade){
			if (it->GE == (it-1)->GE){
				it->rank = (it-1)->rank;
			}
			else it->rank = rank;
		}
		else it->rank = rank;
	}

	for (Student i : stuList){
		for (int j = 0; j < k; j++){
			if (admission[i.choice[j]].size() < max[i.choice[j]]){
				//如果学校没录满 则录取并把学生id加入学校录取名单
				admission[i.choice[j]].push_back(i);
				break;
			}
			else {
				//如果学校已经录满，但是该学生排名和该学校最后一个人排名相同则破格录取
				if (admission[i.choice[j]].size()>0)
					if (i.rank == (admission[i.choice[j]].end()-1)->rank){
						admission[i.choice[j]].push_back(i);
						break;
					}
			}
		}
	}

	for (int i = 0; i < m; i++){
		if (admission[i].size() > 0){
			sort(admission[i].begin(),admission[i].end(),cmp_2);
			for (vector<Student>::iterator j = admission[i].begin(); j != admission[i].end()-1; j++){
				printf("%d ",j->id);
			}
			printf ("%d",(admission[i].end()-1)->id);
		}
		printf("\n");
	}
	return 0;
}
