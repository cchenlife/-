#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
vector<string> result;
vector<vector<int>> dp;
void traceback(int m, int n, const string& str1, const string& str2, string str){
	while (m > 0 && n > 0){
		if (str1[m-1] == str2[n-1]){
			str = str + str1[m - 1];
			m--;
			n--;
		}
		else{
			if (dp[m - 1][n] > dp[m][n - 1])
				m--;
			else if (dp[m - 1][n] < dp[m][n - 1])
				n--;
			else
			{
				traceback(m - 1, n, str1, str2, str);
				traceback(m, n - 1, str1, str2, str);
				return;
			}
		}
	}
	str.reserve();
	result.push_back(str);
}
int main(){
	string str1 = "ABCBDAB";
	string str2 = "BDCABA";
	dp = vector<vector<int>>(str1.size() + 1, vector<int>(str2.size() + 1));
	for (int i = 0; i < str1.size(); i++){
		for (int j = 0; j < str2.size(); j++){
			if (str1[i] == str2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i+1][j],dp[i][j+1]);
		}
	}

	cout << dp[str1.size()][str2.size()] << endl;
	traceback(str1.size(), str2.size(), str1, str2, "");
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	return 0;
}
