/*

*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<set<int>> nums;
vector<bool> mark;
void dfs(int index, set<int>& rela){
	mark[index] = true;
	set<int>::iterator itr = rela.begin();
	for (; itr != rela.end(); itr++){
		if (mark[*itr] == false){
			dfs(*itr, nums[*itr]);
			mark[*itr] = true;
		}
	}
}
int main(){
	int n;
	cin >> n;
	nums = vector<set<int>>(n, set<int>());
	mark = vector<bool>(n, false);
	for (int i = 0; i < n; i++){
		int temp;
		while (cin >> temp){
			if (temp == 0)
				break;
			else
				nums[i].insert(temp - 1);
		}
	}
	for (int i = 0; i < n; i++){
		for (set<int>::iterator itr = nums[i].begin(); itr !=nums[i].end(); itr++)
			nums[*itr].insert(i);
	}
	int result = 0;
	for (int i = 0; i < n; i++){
		if (mark[i] == false){
			dfs(i, nums[i]);
			result++;
		}
	}
	cout << result << endl;
	return 0;
}
