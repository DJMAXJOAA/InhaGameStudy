class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prev = -99999;
        int ans = 0;
        for (auto i : intervals) {
            if (i[0] >= prev) prev = i[1]; ///��ġ�� �ʴ� ��� 
            else { // ��ġ�� ���
                ans++;
                prev = min(prev, i[1]); //�� ���� �� ������ �ð� ���� ���� ����
            }

        }
        return ans;
    }
};