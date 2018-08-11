/*
题目描述
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，
你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 
ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
动态规划问题
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, k, d;
	long long int res = 0;
	cin >> n;
	vector<int> nums;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}
	cin >> k >> d;
	long long int maxnum[11][50], minnum[11][50];
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			maxnum[i][j] = 0;
			minnum[i][j] = 0;
		}
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i <= k; i++)
		{
			if (i == 1)
			{
				maxnum[i][j] = nums[j];
				minnum[i][j] = nums[j];
			}
			else {
				for (int m = 1; m <= d; m++){
					if (j - m >= 0 && j - m < n)
					{
						maxnum[i][j] = max(maxnum[i][j], max(maxnum[i - 1][j - m] * nums[j], minnum[i - 1][j - m] * nums[j]));
						minnum[i][j] = min(minnum[i][j], min(maxnum[i - 1][j - m] * nums[j], minnum[i - 1][j - m] * nums[j]));
					}
				}
			}
		}
		res = max(res, maxnum[k][j]);
	}
	cout << res;
	return 0;
}
