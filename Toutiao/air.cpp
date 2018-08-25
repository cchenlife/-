/*
Once again(周期数列的最长非递减子序列)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	int n, t;
	cin >> n >> t;
	vector<int> seq;
	map<int, int> mp;
	int maxnum = 0, maxcnt = 0;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		seq.push_back(temp);
		mp[temp]++;
		if (mp[temp] > maxcnt) {
			maxnum = temp;
			maxcnt = mp[temp];
		}
	}
	vector<int> temp(seq);
	for (int i = 0; i < min(n, t)-1; i++){
		seq.insert(seq.end(),temp.begin(),temp.end());
	}
	int val = 0;
	vector<int> dp(seq.size(),0);
	for (int i = 0; i < seq.size(); i++) {
		int pos = upper_bound(dp.begin(), dp.begin()+val, seq[i]) - dp.begin();
		if (pos == val) dp[val++] = seq[i];
		else dp[pos] = seq[i];
	}
	if (t > n) val = val + (t - n) * maxcnt;

	cout<<val;
}
