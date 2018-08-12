/*
P为给定的二维平面整数点集。定义 P 中某点x，如果x满足 P 中任意点都不在 x 的右上方区域内（横纵坐标都大于x），则称其为“最大的”。求出所有“最大的”点的集合。（所有点的横坐标和纵坐标都不重复, 坐标轴范围在[0, 1e9) 内）

如下图：实心点为满足条件的点的集合。请实现代码找到集合 P 中的所有 ”最大“ 点的集合并输出。



输入描述:
第一行输入点集的个数 N， 接下来 N 行，每行两个数字代表点的 X 轴和 Y 轴。
对于 50%的数据,  1 <= N <= 10000;
对于 100%的数据, 1 <= N <= 500000;

输出描述:
输出“最大的” 点集合， 按照 X 轴从小到大的方式输出，每行两个数字分别代表点的 X 轴和 Y轴。

输入例子1:
5
1 2
5 3
4 6
7 5
9 0

输出例子1:
4 6
7 5
9 0
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct myPoint{
	int x, y;
	myPoint(int a, int b){
		x = a;
		y = b;
	}
	bool operator< (const myPoint& p1){
		return x < p1.x;
	}
};
bool cmp(myPoint& p1, myPoint& p2){
	return p1 < p2;
}
int main(){
	int n;
	vector<myPoint> points;
	cin >> n;
	for (int i = 0; i<n; i++){
		int x, y;
		cin >> x >> y;
		points.push_back(myPoint(x, y));
	}
	if (points.size() == 1){
		cout << points[0].x << " " << points[0].y << endl;
		return 0;
	}
	sort(points.begin(), points.end(), cmp);

	vector<myPoint> result;
	int maxy = -1;
	for (int i = n - 1; i >= 0; i--){
		if (points[i].y>maxy){
			result.push_back(points[i]);
			maxy = points[i].y;
		}
	}
	for (int i = result.size() - 1; i>=0; i--)
		cout << result[i].x << " " << result[i].y << endl;
	return 0;
}
