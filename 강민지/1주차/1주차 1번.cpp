class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;

        int i=0;
        bool flag=false;
        int start=newInterval[0];;
        int end=newInterval[1];

        while(i<intervals.size() && intervals[i][1]<newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        while(i<intervals.size() && intervals[i][0]<=newInterval[1])
        {
            
            start=min(intervals[i][0],start);
            end=max(intervals[i][1],end);
            i++;
        }
        result.push_back({start,end});

        while(i<intervals.size())
        {
            result.push_back(intervals[i]);
            i++;
        }
       
        return result;
    }
};
