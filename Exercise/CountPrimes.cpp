/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

计算小于n的素数个数

思路：

如果一个数m是素数，那么所有m * k就都不是素数。另外2是最小的素数
*/
#include <iostream>
#include<vector>

int main(){
	int n;
	cin >> n;
	if (n < 2){
		cout << "0" << endl;
		return 0;
	}
	vector<bool> nums(n, true);
	int count = 0;
	for (int i = 2; i < n; i++){
		if (nums[i]){
			count++;
			for (int j = 2; j*i < n; j++)
				nums[i*j] = false;
		}
	}
	cout << count << endl;
	return 0;
}
