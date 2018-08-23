/*
给定两个数R和n，输出R的n次方，其中0.0<R<99.999, 0<n<=25

输入描述:
多组测试用例，请参考例题的输入处理 输入每行一个浮点数 R 其中0.0 < R <99.999， 一个整数 n 其中0 < n <=25


输出描述:
输出R的n次方

输入例子1:
95.123 12 0.1 1

输出例子1:
548815620517731830194541.899025343415715973535967221869852721 0.1
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s, a, b;//输入字符串，乘数，被乘数
int n, l;//幂，小数点位置
//小数化为整数，并翻转数据
void init(){
	l = s.find('.');
	if (l >= 0) {
		s.erase(l, 1);
		l = (s.length() - l)*n;
	}
	reverse(s.begin(), s.end());
}
//数据a,b相乘
void multiply(){
	for (int i = 0; i < a.length(); ++i)
	for (int j = 0; j < b.length(); ++j){
		s[i + j] += (a[i] - 48)*(b[j] - 48);
		s[i + j + 1] += s[i + j] / 10;
		s[i + j] %= 10;
	}
	for (int i = 0; i < s.length(); ++i)s[i] += '0';
}
//控制幂次相乘
void calculate(){
	a.assign(s);
	while (--n){
		b.assign(s);
		s = string(a.length() + b.length(), 0);
		multiply();
	}
	reverse(s.begin(), s.end());
}
//格式输出
void printout(){
	if (l > 0)
		s.insert(s.length() - l, ".");
	int start = 0, end = s.length() - 1;
	while (s[start] == '0'&&s[start + 1] != '.')++start;
	while (s[end] == '0')--end;
	s = s.substr(start, end - start + 1 - (s[end] == '.'));
	cout << s << endl;
}
int main(){
	while (cin >> s >> n) {
		init();
		calculate();
		printout();
	}
	return 0;
}


#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

//数据a,b相乘
void multiply(string& s,string& a,string& b){
	for (int i = 0; i < a.length(); ++i)
	for (int j = 0; j < b.length(); ++j){
		s[i + j] += (a[i] - 48)*(b[j] - 48);
		s[i + j + 1] += s[i + j] / 10;
		s[i + j] %= 10;
	}
	for (int i = 0; i < s.length(); ++i)s[i] += '0';
}

int main(){
	string s;
	int n;
	while (cin >> s >> n) {
		int l = s.find('.');
		if (l >= 0) {
			s.erase(l, 1);
			l = (s.length() - l)*n;
		}
		reverse(s.begin(), s.end());
		string a, b;
		a.assign(s);
		while (--n){
			b.assign(s);
			s = string(a.length() + b.length(), 0);
			multiply(s,a,b);
		}
		reverse(s.begin(), s.end());
		if (l >= 0)
			s.insert(s.length() - l, ".");
		int start = 0, end = s.length() - 1;
		while (s[start] == '0'&&s[start + 1] != '.')++start;
		while (s[end] == '0')--end;
		s = s.substr(start, end - start + 1 - (s[end] == '.'));
		cout << s << endl;
		s.clear();
	}
	return 0;
}
