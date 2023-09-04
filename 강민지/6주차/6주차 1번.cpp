class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int compare = intervals[0][1];
        int answer = 0;

        for(int i = 1; i < intervals.size(); i++)
        {
            if(compare > intervals[i][0])
            {
                answer++;
                compare = min(compare, intervals[i][1]);
            }
            else
            {
                compare = intervals[i][1];
            }   
        }

        return answer;
    }
};
