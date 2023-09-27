[9주차 4번] / Reverse Bits / 12분 / https://leetcode.com/problems/reverse-bits/submissions/

[문제 접근]
사용 알고리즘 = 비트 연산
1. 2^31부터 2씩 깎으면서 계산

[시간 복잡도] 
O(log n) : 이진 표현이니까 log n
[공간 복잡도] 
O(1) : 상수 공간

[개선점]
1. pow(2, 31)을 미리 계산해서 상수값으로 저장해서 최적화 가능

[다른 풀이 방법]
1. 비트 시프트 연산

Time taken : 11 m 59 s
Runtime 0ms
Beats 100.00 % of users with C++
Memory 6.50MB
Beats 5.48 % of users with C++

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
비트 시프트 연산

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int shift = 31; // 시작시 31비트를 왼쪽으로 이동

        while (n) {
            result |= (n & 1) << shift; // n의 오른쪽 비트를 결과의 shift 위치에 추가
            n >>= 1; // n을 오른쪽으로 시프트
            shift--; // 다음 위치로
        }

        return result;
    }
};
