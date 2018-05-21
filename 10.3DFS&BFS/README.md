# 如何进行连通图划分
## 1.先初始化所有节点都不属于任何小组
vector<> gang[maxn];
belong[maxn] = {-1,-1....-1}
gangNum = 0;
## 2.如果有节点
for(遍历所有节点){
	if (belong[节点]不属于任何gang){
		gangNum++
		BFS或DFS 搜索该节点在搜索过程成把 搜到的节点放入该gang[gangNum]
	}
}
