[10주차 2번] / Longest Consecutive Sequence / 1시간 / https://leetcode.com/problems/longest-consecutive-sequence/

[문제 접근]
사용 알고리즘 = 해시 테이블 (unordered_set) :: O(n)
1. nums 배열을 해시테이블에 대입
2. 연속되는 배열의 시작점 찾기 (현재 원소값보다 1 작은 값이 있는지? -> 없으면 시작점이 될 수 있음)
3. 연속되는 숫자를 while 문 안에서 찾기 (원소 삭제는 필수 부분은 아님)

[추가 설명]
1. 해시 테이블은 정렬이 되지 않은 상태로 대입된다 (반복자를 사용하는 것이 의미가 없다)
2. 접근 속도는 O(1) ~ 최악의 상황에서 O(n)으로, 원소에 굉장히 빠르게 접근할 수 있음

[개선점]
1. 문제가 미리 큰 배열을 선언하지 않으면서(배열 사용에 제약 O), 특정 원소에 빠르게 접근해야 하는 경우 unordered_set
2. 정렬이 되야 하는 경우에는 일반 set 사용하기

[다른 풀이 방법]
1. 정렬 :: O(n log n)

Time taken : 59 m 27 s
Runtime 129ms
Beats 57.48 % of users with C++
Memory 70.79MB
Beats 9.65 % of users with C++

// [9,1,4,7,3,-1,0,5,8,-1,6] -> 7

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        unordered_set<int> save(nums.begin(), nums.end());
        int result = 1;

        for (int num : nums)
        {
            // 찾으려는 수보다 연속되는 작은 수가 있으면 패스
            // 찾으려는 값이 정수값이니 save.count(nums - 1)로 바꿔서 사용 가능, 기능에 크게 차이 없음
            if (save.find(num - 1) == save.end())
            {
                int findVal = num;
                int current = 1;

                while (save.find(findVal + 1) != save.end())
                {
                    findVal++;
                    current++;
                    // 다음 체크할때 나오지 말라고 값 지우기
                    save.erase(findVal);
                }

                result = max(result, current);
            }
        }

        return result;
    }
};

[다른 풀이 방법]
정렬::O(n log n)
1. set의 자동 정렬을 이용했음
2. unordered_map과 달리 정렬해서 비교하니, 반복자 사용은 가능 / 하지만 정렬에 시간 소요

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    set<int> num_set(nums.begin(), nums.end());
    int longestStreak = 1;
    int currentStreak = 1;

    for (int num : num_set) {
        // 현재 숫자가 이전 숫자의 연속이라면 스트릭을 증가시킵니다.
        if (num_set.find(num - 1) != num_set.end()) {
            currentStreak++;
            longestStreak = max(longestStreak, currentStreak);
        }
        else {
            // 연속이 끊겼다면 스트릭을 재설정합니다.
            currentStreak = 1;
        }
    }
    return longestStreak;
}
