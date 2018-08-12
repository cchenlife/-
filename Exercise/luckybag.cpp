/*
题目描述
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。

输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)

输出描述:
输出可以产生的幸运的袋子数

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int findcount(vector<int> nums,int start,int addnum,long multinum){
	int result = 0;

	for (int i = start; i < nums.size(); i++){
		addnum += nums[i];
		multinum*=nums[i];
		if (addnum >multinum){
			result = result + 1 + findcount(nums, i + 1, addnum, multinum);
		}
		else if (nums[i] == 1)
			result = result + findcount(nums, i + 1, addnum, multinum);
		else
			break;
		addnum -= nums[i];
		multinum/=nums[i];
		for (; i < nums.size()-1 && nums[i]==nums[i+1]; i++);
	}
	return result;
	
}
int main(){
	int count;
	vector<int> nums;

	cin >> count;
	int num;
	for (int i = 0; i < count; i++){
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	cout << findcount(nums, 0, 0, 1) << endl;

	return 0;
}
