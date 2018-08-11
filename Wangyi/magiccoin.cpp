/*
小易准备去魔法王国采购魔法神器,购买魔法神器需要使用魔法币,但是小易现在一枚魔法币都没有,但是小易有两台魔法机器可以通过投入x(x可以为0)个魔法币产生更多的魔法币。
魔法机器1:如果投入x个魔法币,魔法机器会将其变为2x+1个魔法币
魔法机器2:如果投入x个魔法币,魔法机器会将其变为2x+2个魔法币
小易采购魔法神器总共需要n个魔法币,所以小易只能通过两台魔法机器产生恰好n个魔法币,小易需要你帮他设计一个投入方案使他最后恰好拥有n个魔法币。 
输入描述:
输入包括一行,包括一个正整数n(1 ≤ n ≤ 10^9),表示小易需要的魔法币数量。


输出描述:
输出一个字符串,每个字符表示该次小易选取投入的魔法机器。其中只包含字符'1'和'2'。

输入例子1:
10

输出例子1:
122

思路：dfs会超时->数学规律：
     若为奇数，最后一步一定执行了1
     若为偶数，最后一步一定执行了2
     
dfs:
#include<iostream>
#include<string>
using namespace std;
long n;
string result;
void dfs(long target, string str){
	if (target == n){
		result = str;
		return;
	}

	string temp1 = str + "1";
	string temp2 = str + "2";
	if (target*2<n){
		dfs(target * 2 + 1, str + "1");
		dfs(target * 2 + 2, str + "2");
	}
	return;
}
int main(){
	cin >> n;
	string temp = "";
	dfs(0, temp);
	cout << result << endl;

	return 0;
}
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	string result = "";
	while (n != 0){
		if (n % 2 == 1){
			result += "1";
			n = (n - 1) / 2;
		}
		else{
			result += "2";
			n = (n-2) / 2;
		}
	}
	reverse(result.begin(), result.end());

	cout << result << endl;

	return 0;
	
}
