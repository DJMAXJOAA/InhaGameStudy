[12���� 2��] / House Robber / 11�� / https://leetcode.com/problems/house-robber/description/

[���� ����]
��� �˰��� = ���� ��ȹ��(Dynamic Programming) O(n), O(n)
1. nums �迭�� ������ ũ���� dp �迭 ����
2. 2���� ��츦 ���ϴ� ��ȭ���� �����, �ִ밪�� dp�迭�� ����
3. dp �迭�� ������ �� ��ȯ

[������]
1. ������ ũ���� dp�迭�� ������ �ʿ䰡 ���� (�ΰ��� ���� ���ϸ� �Ǳ� ����)

[�ٸ� Ǯ�� ���]
1. ���� ��ȹ��(Dynamic Programming) O(n), O(1)

Time taken : 11 m 5 s
Runtime 0ms
Beats 100.00 % of users with C++
Memory 8.44MB
Beats 6.64 % of users with C++

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        if (size == 2)
        {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(size);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[size - 1];
    }
};

[�ٸ� Ǯ�� ���]
���� ��ȹ��(Dynamic Programming) O(n), O(1)
1. �ΰ��� ���� ���Ͽ� ���� ���⵵�� ������ �� ����

int rob(vector<int>& nums) {
    int prev1 = 0, prev2 = 0;
    for (int num : nums) {
        int temp = prev1;
        prev1 = max(prev2 + num, prev1);
        prev2 = temp;
    }
    return prev1;
}
