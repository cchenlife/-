/*牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。*/
c#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void dfs(vector<long>& food, int index, long count, int n, long& result){
	if (count<0)
		return;
	result++;
	for (int i = index; i<n; i++)
		dfs(food, i + 1, count - food[i], n, result);
}
int main(){
	int n;
	long count;
	cin >> n >> count;
	vector<long> food;
	long sum = 0;
	for (int i = 0; i<n; i++){
		int temp;
		cin >> temp;
		sum += temp;
		food.push_back(temp);
	}
	if (sum < count){
		long result = pow(2, n);
        cout<<result<< endl;
		return 0;
	}
	long result = 0;
	dfs(food, 0, count, n, result);
	cout << result << endl;

	return 0;
}
