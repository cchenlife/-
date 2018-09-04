/*
八卦阵相传是由诸葛亮创设的一种战斗队形和兵力部署，由八种阵势组成。为了方便，采用矩阵来描述一个八卦阵，它由八个单阵组成，
每个单阵由多个兵力区域组成形成一种阵势，如下图所示，其中数字为一个兵力区域的士兵个数。假设单阵与单阵之间兵力区域不会相
邻，且单阵中每个兵力区域至少存在一个相邻兵力区域（注：相邻是指在其左上，正上，右上，右方，右下，正下，左下，左方与其相
邻），请用最快的速度计算出八个单阵中的兵力（士兵个数）的最大值和最小值。

输入：
20 20
34 0 0 0 0 0 0 0 0 0 0 0 0 0 0 10 0 0 0 30
0 23 10 5 5 0 0 0 5 5 5 5 5 0 0 0 30 0 40 0
0 9 0 0 5 0 0 0 4 4 4 4 4 0 0 0 0 30 0 0
0 8 7 7 0 5 0 0 3 3 3 3 0 0 0 0 7 0 9 0
0 9 0 0 5 0 5 0 0 12 12 0 0 0 0 10 0 0 0 9
0 0 0 0 5 0 0 5 0 12 12 0 0 5 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 12 12 0 0 5 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 5 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 5 0 0 0 0 0 0
40 30 3 6 6 0 0 0 0 0 0 0 0 5 5 0 0 0 10 0
0 0 20 0 0 6 6 0 0 0 0 0 0 0 5 6 5 10 10 0
40 30 3 7 6 0 0 0 0 0 0 0 0 0 0 6 0 0 10 0
0 0 0 0 0 0 0 17 0 0 0 0 17 0 0 6 5 7 7 0
0 0 0 0 0 0 0 0 7 0 0 7 0 0 0 0 0 0 0 0
0 20 0 0 7 0 0 0 0 4 4 0 0 0 0 0 10 0 0 0
0 20 0 0 7 0 0 0 0 4 4 0 0 0 0 0 10 0 0 0
0 20 0 0 7 0 0 0 0 4 4 0 0 0 0 0 10 0 0 0
0 30 0 7 0 0 0 0 0 5 5 0 0 0 0 0 0 10 0 50
0 40 7 0 0 0 0 0 0 5 5 0 0 0 0 0 0 0 50 0
43 30 25 10 50 0 0 0 6 6 6 6 0 0 0 0 0 50 0 0

输出：
323 116
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct dir{
	int x;
	int y;
	dir(int i , int j ){
		x = i;
		y = j;
	}
};
const dir dirs[8] = { dir(1, 1), dir(1, 0), dir(0, 1), dir(-1, -1), dir(-1, 0), dir(0, -1), dir(1, -1), dir(-1, 1) };
void dfs(vector<vector<int>>& map, int m, int n, int i, int j, int& count){
	count += map[i][j];
	map[i][j] = 0;
	for (int k = 0; k < 8; k++){
		int tempx = i + dirs[k].x, tempy = j + dirs[k].y;
		//cout << "x:" << tempx << " y:" << tempy << endl;
		if (tempx >= 0 && tempx < m && tempy >= 0 && tempy < n && map[tempx][tempy] != 0){
			//cout << "x:" << tempx << " y:" << tempy << endl;
			count += map[tempx][tempy];
			map[tempx][tempy] = 0;
			dfs(map, m, n, tempx, tempy, count);
		}
	}
	return;
}
int main(){
	int m, n;
	cin >> m >> n;
	vector<vector<int>> map(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	int minxcount = INT_MAX,maxcount = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			if (map[i][j] != 0){
				int temp = 0;
				dfs(map, m, n, i, j, temp);
				if (temp < minxcount)
					minxcount = temp;
				if (temp>maxcount)
					maxcount = temp;
			}
		}
	}
	cout << "max:" << maxcount << " min:" << minxcount << endl;
	return 0;
}
