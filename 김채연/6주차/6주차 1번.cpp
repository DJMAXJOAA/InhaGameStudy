class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prev = -99999;
        int ans = 0;
        for (auto i : intervals) {
            if (i[0] >= prev) prev = i[1]; ///겹치지 않는 경우 
            else { // 겹치는 경우
                ans++;
                prev = min(prev, i[1]); //두 구간 중 끝나는 시간 느린 구간 삭제
            }

        }
        return ans;
    }
};