给定一个有小写字母组成的字符串S，将其分割成尽量多的子串，并保证每个字母最多只在其中一个子串中出现。
请返回由一个或多个整数表示的分割后各个子串的长度。如：‘ababbacadefgdehijhklij’=  ‘ababbaca‘ + ’defgde‘+ ’hijhklij‘。

https://blog.csdn.net/liqinzhe11/article/details/79165588

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
	string str;
	cin >> str;
	int n = str.size();
	vector<int> ends(n);
	vector<int> results;
	for (int i = 0; i < n; i++)
		ends[i] = str.rfind(str[i]);
	int start = 0, index = 0, end = 0;
	while (index < n)
	{
		end = ends[start];
		while (index < end)
		{
			end = max(end, ends[index]);
			index++;
		}
		results.push_back(end);
		index++;
		start = index;
	}
	
	int cutstart = 0;
	for (int i = 0; i < results.size(); i++){
		cout << cutstart<<" "<<results[i] << " " << str.substr(cutstart, results[i]-cutstart) << endl;
		cutstart = results[i] + 1;
	}

	return 0;
}
