给定一个有小写字母组成的字符串S，将其分割成尽量多的子串，并保证每个字母最多只在其中一个子串中出现。
请返回由一个或多个整数表示的分割后各个子串的长度。如：‘ababbacadefgdehijhklij’=  ‘ababbaca‘ + ’defgde‘+ ’hijhklij‘。

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
	int start = 0;
	int result = ends[start];
	while (result < n){
		int i = start;
		for (; i < result; i++){
			if (ends[i]>result){
				result = ends[i];
				break;
			}
		}
		if (i >= result - 1){
			results.push_back(result);
			if (result + 1 >= n)
				break;
			start = result + 1;
			result = ends[start];
		}


	}
	int cutstart = 0;
	for (int i = 0; i < results.size(); i++){
		cout << cutstart<<" "<<results[i] << " " << str.substr(cutstart, results[i]-cutstart) << endl;
		cutstart = results[i] + 1;
	}

	return 0;
}
