/*
题目描述
继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：首先将电话号码中的每个数字加上8取个位，然后使用对应的大写字母代替 
（"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"）， 然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。

输入描述:
第一行是一个整数T（1 ≤ T ≤ 100)表示测试样例数；接下来T行，每行给定一个分身后的电话号码的分身（长度在3到10000之间）。

输出描述:
输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。

数学规律！
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string * strs = new string[n + 1];

	for (int i = 0; i < n; i++)
		cin >> strs[i];
	for (int i = 0; i < n; i++){
		int count[10] = { 0 };
		for (int j = 0; j < strs[i].size(); j++){
			if (strs[i][j] == 'Z') count[0]++;//0对应2
			if (strs[i][j] == 'O') count[1]++;
			if (strs[i][j] == 'W') count[2]++;//2对应4
			if (strs[i][j] == 'H') count[3]++;
			if (strs[i][j] == 'U') count[4]++;//4对应6
			if (strs[i][j] == 'F') count[5]++;
			if (strs[i][j] == 'X') count[6]++;//6对应8
			if (strs[i][j] == 'S') count[7]++;
			if (strs[i][j] == 'G') count[8]++;//8对应0
			if (strs[i][j] == 'I') count[9]++;
		}
		count[1] = count[1] - count[0] - count[2] - count[4];//1对应3
		count[3] = count[3] - count[8];//3对应5
		count[5] = count[5] - count[4];//5对应7
		count[7] = count[7] - count[6];//7对应9
		count[9] = count[9] - count[8] - count[5] - count[6];//9对应1
		while (count[8]--)
			cout << "0";
		while (count[9]--)
			cout << "1";
		while (count[0]--)
			cout << "2";
		while (count[1]--)
			cout << "3";
		while (count[2]--)
			cout << "4";
		while (count[3]--)
			cout << "5";
		while (count[4]--)
			cout << "6";
		while (count[5]--)
			cout << "7";
		while (count[6]--)
			cout << "8";
		while (count[7]--)
			cout << "9";
		cout << endl;
	}


	return 0;
}
