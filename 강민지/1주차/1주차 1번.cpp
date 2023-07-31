class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;

        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];

        // start가 intervals[i] 범위 안에 없을 때
        while(i<intervals.size() && intervals[i][1]<start)
        {
            result.push_back(intervals[i]); // 통째로 추가
            i++;
        }

        // interval[i] 값이 newInterval 사이에 있을 때
        // max, min 갱신
        while(i<intervals.size() && intervals[i][0]<=end)
        {
            start=min(intervals[i][0],start);
            end=max(intervals[i][1],end);
            i++;
        }
        result.push_back({start,end});

        // newInterval 범위 이후의 interval[i] 값들 추가
        while(i<intervals.size())
        {
            result.push_back(intervals[i]);
            i++;
        }
       
        return result;
    }
};
