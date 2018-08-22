    /*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/
//判断一个数组是否可以分为两个相等的部分
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        sum /= 2;
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,0));
        for(int i = nums[0];i<=sum;i++)
            dp[0][i] = nums[0];
        for(int i = 1;i<nums.size();i++){
            for(int j = nums[i];j<=sum;j++){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i]);
            }
        }
        int result = dp[nums.size()-1][sum];
        if(result==sum)
            return true;
        else return false;
    }
