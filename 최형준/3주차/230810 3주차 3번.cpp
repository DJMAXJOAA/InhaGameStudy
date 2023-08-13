[3주차 3번] / Merge Intervals / 30분 / https://leetcode.com/problems/merge-intervals/
벡터의 배열을 정렬시키고, 범위가 겹치는 부분을 병합시키는 문제

문제 접근
1.  처음에는 intervals의 범위의 두번째 부분부터 마지막까지 반복자를 돌려서, 겹치는 부분의 이전 부분을 erase로 지워버리려고 시도.
    하지만 erase로 지워버리면 반복자가 사라지게 되어 벡터 에러 + 모든 케이스에 적용시키기가 불가능해서 변경
2.  반환하기 위한 2차원 벡터를 새로 선언하고, 중첩되면 현재 반복자의 값을 겹치는 값으로 새로 갱신시킨다.
    그리고 중첩되지 않는 부분이 나오면 이전 반복자를 result 벡터배열에 push_back 시킴
3.  반복자가 마지막 이전이라면, 넣지 않았었던 현재 반복자를 result 배열에 push_back

개선 사항
1.  남이 코드를 봐서 한번에 이해하기 어려울 것 같다 (동작은 정상 작동하지만, 가독성이 좋지 않음)
2.  erase를 사용하지 않는 이상, 반복자를 굳이 사용하지 말고 작성하는게 코드를 더 간결하게 작성할 수 있을 듯 하다
3.  마지막 구간을 체크할 때 상황은 반복문 밖에 있는게 좋을 듯 하다

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