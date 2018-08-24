/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

三种颜色排序，思想类似三区间快排（大于当前数（index表示开始），小于当前数（index表示末尾），等于当前数（index表示末尾））

*/
    void sortColors(vector<int>& nums) {
        int index0 = -1,index1 = 0,index2 = nums.size();
        while(index1<index2){
            if(nums[index1]==0){
                index0++;
                swap(nums[index0],nums[index1]);
                index1++;
            }
            else if(nums[index1]==2){
                index2--;
                swap(nums[index1],nums[index2]);
                index1;
            }
            else
                index1++;
        }
    }
