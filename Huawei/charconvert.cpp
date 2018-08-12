/*
字符串中字母大写变小写，小写变大写

*/
#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	int size = str.size();
	int sub = 'A' - 'a';
	for (int i = 0; i < size; i++){
		if (str[i] >= 'a'&&str[i] <= 'z')
			str[i] = (char)((int)str[i] + sub);
		else if (str[i] >= 'A'&&str[i] <= 'Z')
			str[i] = (char)((int)str[i] - sub);
	}
	cout << str << endl;

	return 0;
}
