[6주차 1번] / Non-overlapping Intervals / 1시간 19분 / https://leetcode.com/problems/non-overlapping-intervals/

문제 접근
1. 간격 배열의 두번째 부분들을 기준으로 오름차순 정렬
2. 반복문을 처음부터 돌면서, 두개의 기준점을 둠(current, i)
3. current의 back이 i의 front보다 크다면 겹침
    1. 겹친다면 result를 올리고, current의 갱신은 하지 않음
    2. 겹치지 않는다면, current를 갱신시킴

관련 알고리즘
1. 간격 스케줄링(Interval Scheduling)
2. 탐욕 알고리즘(Greedy Algorithm)

개선점
1. 범위가 겹치는 알고리즘에 약하니, 좀 더 준비해야 할듯
2. 탐욕 알고리즘에 대해서 더 찾아보기

// Time taken : 1 hr 19 m 46 s
// Runtime 331ms
// Beats 94.55 % of users with C++
// Memory 89.84MB
// Beats 27.75 % of users with C++

bool compare(const vector<int>& a, const vector<int>& b)
{
    return a.back() < b.back();
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        if (intervals.size() == 1)
            return 0;

        int result = 0;
        sort(intervals.begin(), intervals.end(), compare);

        int current = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[current][1] <= intervals[i][0])
            {
                current = i;
            }
            else
            {
                result++;
            }
        }

        return result;
    }
};