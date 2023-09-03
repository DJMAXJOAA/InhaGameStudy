[6���� 1��] / Non-overlapping Intervals / 1�ð� 19�� / https://leetcode.com/problems/non-overlapping-intervals/

���� ����
1. ���� �迭�� �ι�° �κе��� �������� �������� ����
2. �ݺ����� ó������ ���鼭, �ΰ��� �������� ��(current, i)
3. current�� back�� i�� front���� ũ�ٸ� ��ħ
    1. ��ģ�ٸ� result�� �ø���, current�� ������ ���� ����
    2. ��ġ�� �ʴ´ٸ�, current�� ���Ž�Ŵ

���� �˰���
1. ���� �����ٸ�(Interval Scheduling)
2. Ž�� �˰���(Greedy Algorithm)

������
1. ������ ��ġ�� �˰��� ���ϴ�, �� �� �غ��ؾ� �ҵ�
2. Ž�� �˰��� ���ؼ� �� ã�ƺ���

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