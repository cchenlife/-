/*
451. Sort Characters By Frequency (Medium)

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

按照字符出现次数对字符串排序
*/

    string frequencySort(string s) {
        string res = "";
        priority_queue<pair<int, char>> q;
        map<char, int> m;
        for (char c : s) ++m[c];
        for (auto a : m) q.push({a.second, a.first});
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            res.append(t.first, t.second);
        }
        return res;
    }
