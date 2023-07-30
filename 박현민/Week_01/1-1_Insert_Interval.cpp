class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        vector<vector<int>> ans;
        int keep;
        vector<int> tmp(2, 0);
        tmp[0] = newInterval[0];
        tmp[1] = newInterval[1];

        for (int i = 0; i < size; i++)
        {
            if (intervals[i][1] < newInterval[0])
            {
                ans.push_back(intervals[i]);
            }
            else if (newInterval[1] < intervals[i][0])
            {
                keep = i;
                break;
            }
            else
            {
                tmp[0] = min(tmp[0], intervals[i][0]);
                tmp[1] = max(tmp[1], intervals[i][1]);
            }
        }

        ans.push_back(tmp);

        for (int i = keep; i < size; i++)
        {
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};