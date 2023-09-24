[9주차 3번] / Maximum Subarray / 33분 / https://leetcode.com/problems/maximum-subarray/

[문제 접근]
사용 알고리즘 = DP(동적 프로그래밍, 카데인 알고리즘 :: 연속적인 부분 배열의 최대 합)
1. dp배열 vector<int> 선언
2. nums 배열을 돌면서 현재 nums[i]와 이전 dp배열값과 현재 nums[i]를 최대값 비교
3. result와 현재 dp배열 최대값 비교

[시간 복잡도] 
O(n) : 배열 한번 순회
[공간 복잡도] 
O(n) : nums크기의 dp 배열

[개선점]
1. dp 배열의 크기를 nums 배열과 동일하게 할 필요가 없음 (어차피 이전 값과 현재 값만 사용하니까, 크기가 2인 배열이면 충분하다)

[다른 풀이 방법]
1. 분할 정복

Time taken : 33 m 15 s
Runtime 88ms
Beats 33.27 % of users with C++
Memory 70.62MB
Beats 5.24 % of users with C++

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        int result;

        dp[0] = nums[0];
        result = dp[0];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            result = max(dp[i], result);
        }

        return result;
    }
};


[다른 풀이 방법]
분할 정복 :: O(n log n)
1. 분할 : 중앙 위치에서 배열을 두 개로 분할
2. 정복 : 각각의 배열에서 최대 부분 배열 합계를 찾는다. 이후 두 경계에 걸쳐 있는 부분 배열의 합계를 찾아 이 중 가장 큰 값을 선택
4. 결합 : 큰 값들을 합쳐서 최대 합계 찾기

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }

private:
    int maxSubArray(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];  // 기본 경우: 배열에 하나의 요소만 있는 경우

        int mid = left + (right - left) / 2;  // 중간 지점 계산

        // 왼쪽 부분 배열과 오른쪽 부분 배열에서의 최대 합계 찾기
        int leftMax = maxSubArray(nums, left, mid);
        int rightMax = maxSubArray(nums, mid + 1, right);

        // 중앙을 걸쳐 있는 부분 배열의 최대 합계 찾기
        int leftCrossMax = nums[mid], leftCrossSum = 0;
        for (int i = mid; i >= left; i--) {  // 중앙에서 왼쪽으로 확장
            leftCrossSum += nums[i];
            leftCrossMax = max(leftCrossMax, leftCrossSum);
        }

        int rightCrossMax = nums[mid + 1], rightCrossSum = 0;
        for (int i = mid + 1; i <= right; i++) {  // 중앙에서 오른쪽으로 확장
            rightCrossSum += nums[i];
            rightCrossMax = max(rightCrossMax, rightCrossSum);
        }

        // 세 경우(왼쪽 최대, 오른쪽 최대, 중앙 걸친 최대)에서 가장 큰 값을 반환
        return max({ leftMax, rightMax, leftCrossMax + rightCrossMax });
    }
};
