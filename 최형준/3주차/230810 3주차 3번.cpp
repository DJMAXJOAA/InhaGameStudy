[3���� 3��] / Merge Intervals / 30�� / https://leetcode.com/problems/merge-intervals/
������ �迭�� ���Ľ�Ű��, ������ ��ġ�� �κ��� ���ս�Ű�� ����

���� ����
1.  ó������ intervals�� ������ �ι�° �κк��� ���������� �ݺ��ڸ� ������, ��ġ�� �κ��� ���� �κ��� erase�� ������������ �õ�.
    ������ erase�� ���������� �ݺ��ڰ� ������� �Ǿ� ���� ���� + ��� ���̽��� �����Ű�Ⱑ �Ұ����ؼ� ����
2.  ��ȯ�ϱ� ���� 2���� ���͸� ���� �����ϰ�, ��ø�Ǹ� ���� �ݺ����� ���� ��ġ�� ������ ���� ���Ž�Ų��.
    �׸��� ��ø���� �ʴ� �κ��� ������ ���� �ݺ��ڸ� result ���͹迭�� push_back ��Ŵ
3.  �ݺ��ڰ� ������ �����̶��, ���� �ʾҾ��� ���� �ݺ��ڸ� result �迭�� push_back

���� ����
1.  ���� �ڵ带 ���� �ѹ��� �����ϱ� ����� �� ���� (������ ���� �۵�������, �������� ���� ����)
2.  erase�� ������� �ʴ� �̻�, �ݺ��ڸ� ���� ������� ���� �ۼ��ϴ°� �ڵ带 �� �����ϰ� �ۼ��� �� ���� �� �ϴ�
3.  ������ ������ üũ�� �� ��Ȳ�� �ݺ��� �ۿ� �ִ°� ���� �� �ϴ�

// Runtime 22ms
// Beats 99.20 % of users with C++
// Memory 18.99mb
// Beats 70.54 % of users with C++

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (auto itr = intervals.begin() + 1; itr != intervals.end(); ++itr)
        {
            auto prev_itr = prev(itr, 1);
            if (prev_itr->at(0) <= itr->at(0) && itr->at(0) <= prev_itr->at(1))
            {
                itr->front() = prev_itr->front();
                itr->back() = max(prev_itr->back(), itr->back());
            }
            else
            {
                result.push_back(*prev_itr);
            }

            if (itr == prev(intervals.end(), 1))
                result.push_back(*itr);
        }

        return result;
    }
};