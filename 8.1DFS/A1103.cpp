#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int n,k,p;
int sum = 0;	//底数加和
int sumPow = 0;		//乘方后的值
vector<int> output, temp;		//output 存放最终输出结果，temp存放DFS中临时内容
void DFS(int index, int nowK, int nowSum, int nowSumPow){
	if (nowK == k){							//当此时temp中数量达到k个 是一个边界条件
		if (nowSumPow == n && nowSum > sum){	// 满足这个要求才能够把temp传给output
			sum = nowSum;
			output = temp;					// vector实例对象 是引用
		}
		return ;
	}
	if (index == 0 || nowSumPow > n ){		//剪枝条件 大大降低复杂度 不让DFS一路枚举到尽头，就可以调头进入下一个分支枚举
		return ;
	}

	//把当前底数放入temp
	temp.push_back(index);					
	DFS(index,nowK+1,nowSum + index, nowSumPow + pow(index,p));
	//不放入当前底数,即跳过当前数值进入下一个数值
	temp.pop_back();
	DFS(index-1,nowK,nowSum,nowSumPow);
}


int main(){
	scanf ("%d%d%d", &n, &k, &p);
	DFS(int(pow(n,1.0/p)), 0, 0, 0);	//采用pow(n,1.0/p)是因为 如果满足题目要求一定不会存在 比该开次方后的数更大的数
										//减少枚举的情况
	//此时output中有两种情况 一种为题目要求 情况，另一种始终找不到答案 output为空
	if (output.size() != k){
		printf("Impossible\n");
	}
	else{
		printf ("%d = ",n);
		for (int i = 0; i < output.size(); i++){
			printf ("%d^%d",output[i],p);
			if (i != output.size()-1){
				printf (" + ");
			}
		}
		printf("\n");
	}
	return 0;
}
