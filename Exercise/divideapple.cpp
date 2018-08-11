/*
题目描述
n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到
另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。

输入描述:
每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），接下来的一行包含 n 个整数 ai（1 <= ai <= 100）。

输出描述:
输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 -1。

数学！
*/
#include<iostream>
#include<cmath>
using namespace std;


int main(){
	int count;
	cin >> count;
	int * nums = new int[count];
	int sum = 0;
	for (int i = 0; i<count; i++){
		cin >> nums[i];
		sum = sum + nums[i];
	}
	int div = sum / count;
	if (sum%count != 0){
		cout << "-1" << endl;
		return 0;
	}
	bool iftrue = true;
	int subsum = 0;
	for (int i = 0; i<count; i++){
		if (abs(nums[i] - div) % 2 != 0){
			iftrue = false;
			cout << "-1" << endl;
			return 0;
		}
		else
			subsum = subsum + abs(nums[i] - div);
	}

	cout << subsum / 4 << endl;

	return 0;

}
