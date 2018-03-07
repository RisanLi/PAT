/**
 * distance[i]数组表示第i个节点到第1个节点的距离
 *
 */

#include <cstdio>
#include <algorithm>

int main(){
	int distance[100001] = {0};
	int n;			//表示n个节点
	int sumDistance = 0;	//表示总距离
	int toNextVertexDistance;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){		//计算各节点到1节点的距离
		scanf("%d",&toNextVertexDistance);
		sumDistance += toNextVertexDistance;
		if (i == n) break;
		distance[i + 1] = sumDistance;
	}
	int m;			//表示m个测试点
	scanf ("%d",&m);
	int vertex1, vertex2;
	int disVertexes = 0;	//两节点间的距离
	int outPut[10000];
	for (int i = 0; i < m; i++){
		scanf ("%d%d",&vertex1,&vertex2);
		if (vertex1 > vertex2) std::swap(vertex1,vertex2);
		
		disVertexes = distance[vertex2] - distance[vertex1];

		outPut[i] = (disVertexes < (sumDistance -  disVertexes) ? disVertexes 
					: (sumDistance - disVertexes));
		disVertexes = 0;
	}

	for (int i =0; i < m; i++){
		printf("%d\n",outPut[i]);
	}

}

