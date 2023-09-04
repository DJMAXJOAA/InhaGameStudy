class Solution {
public:
    static bool compare(vector<int> &a, vector<int>&b)
    {
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]<b[1];

    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //두 번째 값 기준으로 정렬해서, 차례대로 비교
        sort(intervals.begin(), intervals.end(),compare);

        int cnt = 1;
        int temp = intervals[0][1];
        for(int i = 1; i< intervals.size();i++)
        {
            if(intervals[i][0]>=temp)
            {
                cnt++;
                temp = max(temp,intervals[i][1]);
            }
        }
        return intervals.size()-cnt;
    }

};