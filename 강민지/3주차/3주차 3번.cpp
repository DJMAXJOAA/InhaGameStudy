class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int minN = intervals[0][0];
        int maxN = intervals[0][1];
        
        vector<vector<int>> answer;

        for(int i = 1; i < intervals.size(); i++)
        {
            if(minN <= intervals[i][0] && intervals[i][0] <= maxN)
            {
                minN = min(minN, intervals[i][0]);
                maxN = max(maxN, intervals[i][1]); 
            }
            else
            {
                answer.push_back({minN, maxN});
                minN = intervals[i][0];
                maxN = intervals[i][1];
            }
        }

        answer.push_back({minN, maxN});

        return answer;

    }
};
