// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ans = 0;

        vector<int> prv = intervals[0];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(prv[1] > intervals[i][0])
            {
                if(prv[1] > intervals[i][1])
                {
                    prv = intervals[i];
                }
                ans++;
                continue;
            }
            prv = intervals[i];
        }

        return ans;
    }
};
