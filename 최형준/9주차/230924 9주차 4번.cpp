[9���� 4��] / Reverse Bits / 12�� / https://leetcode.com/problems/reverse-bits/submissions/

[���� ����]
��� �˰��� = ��Ʈ ����
1. 2^31���� 2�� �����鼭 ���

[�ð� ���⵵] 
O(log n) : ���� ǥ���̴ϱ� log n
[���� ���⵵] 
O(1) : ��� ����

[������]
1. pow(2, 31)�� �̸� ����ؼ� ��������� �����ؼ� ����ȭ ����

[�ٸ� Ǯ�� ���]
1. ��Ʈ ����Ʈ ����

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


[�ٸ� Ǯ�� ���]
��Ʈ ����Ʈ ����

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int shift = 31; // ���۽� 31��Ʈ�� �������� �̵�

        while (n) {
            result |= (n & 1) << shift; // n�� ������ ��Ʈ�� ����� shift ��ġ�� �߰�
            n >>= 1; // n�� ���������� ����Ʈ
            shift--; // ���� ��ġ��
        }

        return result;
    }
};
