/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h 
is the height of the person and k is the number of people in front of this person who have a height greater than or equal to
h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

还原队列
*/
    static bool cmp(pair<int, int>& p1,pair<int, int>&p2){
        return p1.first==p2.first?p1.second<p2.second:p1.first>p2.first;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        if(people.size()==0)
            return result;
        sort(people.begin(),people.end(),cmp);
        
        result.push_back(people[0]);
        for(int i =1;i<people.size();i++){
            if(people[i].second>result.size()-1)
                result.push_back(people[i]);
            else
                result.insert(result.begin()+people[i].second,people[i]);
        }
        return result;

    }
