class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //// new 입력값 없음
        if (newInterval.empty())
            return intervals;

        // interval이 없음
        if (intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> result;

        // 예외처리 =================================
        // newinterval이 interval 다 잡아먹음
        if (newInterval[1] < intervals[0][0] && newInterval[0] > intervals[intervals.size() - 1][1])
        {
            result.push_back(newInterval);
            return result;
        }

        //newinterval 맨뒤가 interval맨앞보다 작음
        if (newInterval[1] < intervals[0][0])
        {
            result.push_back(newInterval);
            for (int i = 0; i < intervals.size(); i++)
            {
                result.push_back(intervals[i]);
            }
            return result;
        }

        // newinterval 맨앞이 interval맨뒤보다 큼
        if (newInterval[0] > intervals[intervals.size() - 1][1])
        {
            for (int i = 0; i < intervals.size(); i++)
            {
                result.push_back(intervals[i]);
            }
            result.push_back(newInterval);
            return result;
        }

        // 걍 병합 =================================

        int min_val;
        int max_val;

        enum { NONE, MERGING, MERGED };
        int merge = NONE;

        int i;
        for (i = 0; i < intervals.size(); i++)
        {
            if ((newInterval[1] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) && merge == NONE)
            {
                min_val = min(newInterval[0], intervals[i][0]);
                min_val = min(min_val, intervals[i][1]);
                max_val = max(intervals[i][1], newInterval[1]);
                merge = MERGING;
            }
            else if (merge == MERGING)
            {
                vector<int> temp;
                if (max_val < intervals[i][0])
                {
                    temp.push_back(min_val);
                    temp.push_back(max_val);
                    result.push_back(temp);
                    merge = MERGED;
                }
                else if (newInterval[1] <= intervals[i][1] && newInterval[1] >= intervals[i][0])
                {
                    max_val = max(intervals[i][1], newInterval[1]);

                    temp.push_back(min_val);
                    temp.push_back(max_val);
                    result.push_back(temp);
                    merge = MERGED;
                }
            }
            if ((newInterval[1] < intervals[i][0] || newInterval[0] > intervals[i][1]) && merge != MERGING)
            {
                result.push_back(intervals[i]);
            }
        }

        if (merge == NONE)
        {
            result.push_back(newInterval);
            sort(result.begin(), result.end());
        }
        else if (merge == MERGING)
        {
            vector<int> temp;
            temp.push_back(min_val);
            temp.push_back(max_val);
            result.push_back(temp);
            sort(result.begin(), result.end());
        }

        return result;
    }
};