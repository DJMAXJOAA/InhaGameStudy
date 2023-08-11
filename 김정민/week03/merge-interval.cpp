// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        
        sort(intervals.begin(), intervals.end());

        vector<int> prv = intervals[0];
        int idx = 1;

        while(idx < intervals.size())
        {
            vector<int> cur = intervals[idx++];

            // non - overlapping
            if(prv[1] < cur[0])
            {
                ret.push_back(prv);
                prv = cur;
            }
            // overlapping
            else
            {
                // check rear
                int st = prv[0];
                int en = max(prv[1], cur[1]);

                while(idx < intervals.size() && en >= intervals[idx][0])
                {
                    en = max(en, intervals[idx][1]);
                    idx++;
                }

                vector<int> tmp;
                tmp.push_back(st);
                tmp.push_back(en);
                prv = tmp;
            }
        }
        ret.push_back(prv);

        return ret;
    }
};