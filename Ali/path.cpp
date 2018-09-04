/*
三年二班的同学们要去郊游了，他们决定所有人都从一个地方出发，但是每个人都要有不同的路线，最终完成一次郊游。所以他们想知道，在它们去的公园里，究竟有多少种不同的路线供选择。公园可以被描述为一个具有N个结点，M条有向边的图，你要做的任务就是，选择其中某个点，使得其能够产生尽量多的从这个点出发的路线。
提示：此处可以利用node代表结点的总数，结点编号从0到node-1。edge用来描述边。你的程序应该返回路径最多的结点对应的路径数。
注意：所有的边都是有向边！数据输入将保证不包含环路，不包括重复的边。
输入数据示例：
node = 4  edge = {{0, 1}, {1, 2}, {2, 3}, {0, 2}}，包含4条有向边
输出结果：5
示例解释：显然，0号节点应该是起点。对应的5条路线为：
0 1
0 1 2
0 1 2 3
0 2
0 2 3

输入：
4
4 2
0 1
1 2
2 3
0 2
输出：
5

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dfs(vector<vector<int>>& graph, int n, int index, int pathnum){
	for (int i = 0; i < n; i++){
		if (graph[index][i] != 0)
			pathnum = 1 + dfs(graph, n, i, pathnum);
	}
	return pathnum;
}
int main(){
	int n,m,ed;
	cin >> n;
	cin >> m >> ed;
	vector<vector<int>> graph(m,vector<int>(m,0));
	for (int i = 0; i < n; i++){
		int start, end;
		cin >> start >> end;
		graph[start][end] = 1;
	}
	int path = 0;
	for (int i = 0; i < n; i++){
		path = max(path, dfs(graph, n, i, 0));
	}
	cout << path << endl;
	return 0;
}
