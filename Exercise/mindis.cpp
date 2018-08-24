/*
给定两个字符串m和n，只允许进行如下三种操作：

插入，例如：ab -> abc
删除，例如：abc -> ab
替换，例如：abc -> abd
那么请求出将m变成n的最小操作次数（也就是最小编辑距离）
*/
#include <algorithm>
#include <iostream>
#include <string>
#include<vector>

using namespace std;

int mindis(string str1, string str2){
	int size1 = str1.size(), size2 = str2.size();
	vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
	for (int i = 0; i <= size1; i++)
		dp[i][0] = i;
	for (int i = 0; i <= size2; i++)
		dp[0][i] = i;
	for (int i = 1; i <= size1; i++){
		for (int j = 0; j <= size2; j++){
			if (str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))+1;
		}
	}
	return dp[size1][size2];
}
int main(){
	string str1, str2;
	cin >> str1 >> str2;
	int result = mindis(str1, str2);
	cout << result << endl;

	return 0;
}
