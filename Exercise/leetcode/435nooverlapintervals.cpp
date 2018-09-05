/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
    
贪心算法：按区间开始时间排序，检查是否与上一个重叠，若重叠则删除结束时间大的区间。

*/
    
    static bool cmp(const Interval& int1,const Interval& int2){
        return int1.start<int2.start;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int i = 1;
        int count = 0;
        while(i<intervals.size()){
            if(intervals[i].start<intervals[i-1].end){
                count++;
                if(intervals[i].end<intervals[i-1].end)
                    intervals.erase(intervals.begin()+i-1);
                else
                    intervals.erase(intervals.begin()+i);
            }
            else
                i++;
        }
        return count;
    }
