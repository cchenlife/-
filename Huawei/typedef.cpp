/*
编译c++ typedef语句，判断是否合法，若合法输出原始数据类型
*/
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map<string, string> typemap;

string basic[] = { "int", "char", "float", "double","bool" ,"long","void"};
const int size = 7;
bool addtype(string str);
int main(){
	string str;
	getline(cin, str);
	if (str.size() == 0){
		cout << "none" << endl;
		return 0;
	}
	vector<string> strs;
	char *temp = new char[str.size()];
	strcpy(temp, str.c_str());
	char* tmpStr = strtok(temp, ";");
	while (tmpStr != NULL)
	{
		string tmp(tmpStr);
		strs.push_back(tmp);
		tmpStr = strtok(NULL, ";");
	}
	for (int i = 0; i < strs.size(); i++)
	if (!addtype(strs[i])){
		cout << "none" << endl;
		return 0;
	}
	string target;
	cin >> target;

	int pcount = 0;
	string result="";
	while (typemap.count(target) != 0){
		result = typemap[target];
		int index1 = result.rfind("*");
		while (index1 != -1){
			result = result.substr(0, index1);
			pcount++;
			index1 = result.rfind("*");
		}
		target = result;
	}
	if (result.size() == 0){
		cout << "none" << endl;
		return 0;
	}

	if (pcount != 0){
		cout << result;
		for (int i = 0; i < pcount; i++)
			cout << " *";
	}
	else
		cout << result << endl;

	return 0;
}
bool addtype(string str){
	vector<string> strs;
	char *temp = new char[str.size()];
	strcpy(temp, str.c_str());
	char* tmpStr = strtok(temp, " ");

	while (tmpStr != NULL)
	{
		string tmp(tmpStr);
		strs.push_back(tmp);
		tmpStr = strtok(NULL, " ");
	}
	if (find(basic, basic + size, strs[1]) == basic + size){
		bool find = false;
		map<string, string>::iterator itr = typemap.begin();
		for (; itr != typemap.end(); itr++){
			if (itr->second == strs[1])
				find = true;
		}
		if (find == false)
			return false;
	}
	typemap.insert(pair<string, string>(strs[2], strs[1]));

	return true;
}
