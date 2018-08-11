/*
题目描述
请设计一个算法能够完成两个用字符串存储的整数进行相加操作，对非法的输入则返回error
输入描述:
输入为一行，包含两个字符串，字符串的长度在[1,100]。
输出描述:
输出为一行。合法情况输出相加结果，非法情况输出error

*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	//输入非法判断（ASCII码），正负数判断
	string stra, strb;
	while (cin >> stra >> strb)
	{
		bool ifbreak = false;
		for (int i = 0; i<stra.size(); i++)
		if (stra[i]<'0' || stra[i]>'9'){
			cout << "error" << endl;
			ifbreak = true;
			break;
		}
		if (ifbreak == true)
			break;
		for (int i = 0; i<strb.size(); i++)
		if (strb[i]<'0' || strb[i]>'9')
		{
			cout << "error" << endl;
			ifbreak = true;
			break;
		}
		if (ifbreak == true)
			break;
		string ret;
		int carry = 0;
		int i = stra.size() - 1;
		int j = strb.size() - 1;
		while (i >= 0 && j >= 0)
		{
			int sum = (stra[i] - '0') + (strb[j] - '0') + carry;
			carry = sum / 10;//计算carry和sum不能调换顺序
			sum = sum % 10;
			ret = ret + to_string(sum);
			i--;
			j--;
		}
		while (i >= 0)
		{
			int sum = (stra[i] - '0') + carry;
			carry = sum / 10;
			sum = sum % 10;
			ret = ret + to_string(sum);
			i--;
		}
		while (j >= 0)
		{
			int sum = (strb[j] - '0') + carry;
			carry = sum / 10;
			sum = sum % 10;
			ret = ret + to_string(sum);
			j--;
		}
		if (carry)
			ret = ret + '1';
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
	}
	return 0;
}
