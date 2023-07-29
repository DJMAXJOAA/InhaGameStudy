// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int idx = 0;

        int st = newInterval[0];
        int en = newInterval[1];

        while(idx < intervals.size() && intervals[idx][1] < st)
        {
            res.push_back(intervals[idx++]);
        }

        // overlapping
        while(idx < intervals.size() && intervals[idx][0] <= en)
        {
            st = min(intervals[idx][0], st);
            en = max(intervals[idx][1], en);
            idx++;
        }
        vector<int> tmp;
        tmp.push_back(st);
        tmp.push_back(en);
        res.push_back(tmp);

        while(idx < intervals.size())
        {
            res.push_back(intervals[idx++]);
        }

        return res;
    }
};