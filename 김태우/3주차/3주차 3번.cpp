class Solution
{
    static bool Compare(vector<int>& a, vector<int>& b)
    {
        return(a[0] < b[0]);
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.empty()) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), Compare); //ascending order

        int index = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[index][1] >= intervals[i][0])
            {
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
                // include problem
            }

            else
            {
                ans.push_back(intervals[index]);
                index = i;
            }
        }

        ans.push_back(intervals[index]);

        return ans;
    }
};