/*

*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool isdouble(string str1, string str2){
	if (str1.size() != str2.size())
		return false;
	int size = str1.size();
	for (int i = 0; i < str1.size(); i++){
		string temp = str1.substr(i, size) + str1.substr(0, i);
		if (temp == str2)
			return true;
		reverse(temp.begin(), temp.end());
		if (temp == str2)
			return true;
	}
	return false;
}
int main(){
	int n;
	cin >> n;
	int m;
	while (cin >> m){
		vector<string> strs(m);
		for (int i = 0; i < m; i++)
			cin >> strs[i];
		bool result = false;
		for (int i = 0; i < m-1; i++){
			for (int j = i + 1; j < m; j++)
			if (isdouble(strs[i], strs[j])){
				result = true;
				break;
			}
			if (result)
				break;
		}
		if (result)
			cout << "Yeah" << endl;
		else
			cout << "Sad" << endl;
	}
	return 0;
}
