[16주차 2번] / Jump Game / https://leetcode.com/problems/jump-game/description/

[문제 접근] 동적 프로그래밍 O(n^2), O(n)
1. 각 인덱스에 대해 모든 점프 여부를 체크하고, 마지막 인덱스 체크배열 값을 반환

[다른 풀이 방법]
1. 그리디 알고리즘
2. 백 트래킹

Time taken : 16 m 52 s
Runtime 455ms
Beats 15.97 % of users with C++
Memory 49.09MB
Beats 19.29 % of users with C++

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;

        vector<bool> check(nums.size() + 1);
        if (nums[0] == 0)
            return false;

        check[0] = true;

        int size = nums.size();
        int done;
        for (int i = 0; i < size - 1; i++)
        {
            if (check[i] == false)
                continue;

            if (i + nums[i] >= size)
                return true;

            for (int j = i; j <= i + nums[i]; j++)
            {
                check[j] = true;
            }
        }
        return check[size - 1];
    }
};

그리디 알고리즘
1. 현재까지 도달할 수 있는 최대 인덱스를 갱신하면서, 마지막 인덱스 도달 여부를 확인
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // 현재까지 도달할 수 있는 최대 인덱스
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false; // i가 최대 도달 가능 인덱스를 넘어서면 도달 불가
            maxReach = max(maxReach, i + nums[i]); // 최대 도달 가능 인덱스 업데이트
        }
        return maxReach >= nums.size() - 1; // 마지막 인덱스에 도달 가능한지 확인
    }
};


백 트래킹
1. 각 인덱스마다 점프가 가능한 모든 조합을 체크
2. 매우 비효율적
class Solution {
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (position == nums.size() - 1) return true; // 마지막 인덱스에 도달한 경우

        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                return true; // 다음 위치에서 마지막 인덱스에 도달 가능한 경우
            }
        }
        return false; // 도달 불가능
    }

public:
    bool canJump(vector<int>& nums) {
        return canJumpFromPosition(0, nums); // 시작 위치에서 탐색 시작
    }
};
