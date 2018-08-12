/*
一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。例如,"aaabbaaac"是由下面碎片组成的:'aaa','bb','c'。牛牛现在给定一个字符串,请你帮助计算这个字符串的所有碎片的平均长度是多少。

输入描述:
输入包括一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),s只含小写字母('a'-'z')


输出描述:
输出一个整数,表示所有碎片的平均长度,四舍五入保留两位小数。

如样例所示: s = "aaabbaaac"
所有碎片的平均长度 = (3 + 2 + 3 + 1) / 4 = 2.25

输入例子1:
aaabbaaac

输出例子1:
2.25

输出格式！

*/
#include<iostream>
#include<string>
 
using namespace std;
 
int main(){
    int numcount[26] = { 0 };
    string str;
    cin >> str;
    if (str.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    char temp = str[0];
    int count = 1;
    if (str.size() == 1){
        cout << 1.00 << endl;
        return 0;
    }
    str = str + "!";
    int nums = 0;
    for (int i = 1; i<str.size(); i++){
        if (str[i] == temp)
            count++;
        else{
            numcount[temp - 'a'] += count;
            count = 1;
            temp = str[i];
            nums++;
        }
    }
    float sum = 0;
 
    for (int i = 0; i<26; i++){
        if (numcount[i] != 0){
            sum += numcount[i];
        }
    }
    float result = sum / nums;
    printf("%.2f", result);
    return 0;
 
}
