[13���� 3��] / House Robber II / 16�� / https://leetcode.com/problems/house-robber-ii/description/

[���� ����]
��� �˰��� = dp : O(n), O(1)
1. ù��° ������ ������ �� ������ �ʹ� ���
2. �ι�° ������ ������ ������ �ʹ� ���
3. �ΰ��� ��� �� �� ū ���� ��ȯ

[�ٸ� Ǯ�� ���]
1. ��� + �޸������̼� : O(n), O(n)

Time taken : 16 m 53 s
Runtime 0ms
Beats 100.00 % of users with C++
Memory 8.06MB
Beats 65.79 % of users with C++

class Solution {
public:
    int dp(int start, int end, vector<int>& nums)
    {
        int prev = 0, prev_prev = 0;

        for (int i = start; i < end; i++)
        {
            int temp = prev;
            prev = max(prev_prev + nums[i], prev);
            prev_prev = temp;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        else if (size == 2)
        {
            return max(nums[0], nums[1]);
        }

        return max(dp(0, size - 1, nums), dp(1, size, nums));
    }
};

[�ٸ� Ǯ�� ���]
���(�޸������̼�) : O(n), O(n)
1. �迭�� �̿��ؼ�, �����صΰ� ���� ���ϴ� ���
2. ù ���� �� ���, ���� ���� ��츦 ���� ���

class Solution {
public:
    int memo[100][2]; // �޸������̼��� ���� �迭

    int robHouses(vector<int>& nums, int index, bool robbedFirst, int n) {
        if (index >= n) {
            return 0;
        }
        if (index == n - 1) {
            return robbedFirst ? 0 : nums[index]; // ù ���� �о��ٸ� ������ ���� �� �� ����
        }
        if (memo[index][robbedFirst] != -1) {
            return memo[index][robbedFirst]; // �̹� ���� ���� ���
        }

        // ���� ���� �� ���� ���� �ʴ� ����� �ݾ��� ���
        int robCurrent = nums[index] + robHouses(nums, index + 2, robbedFirst, n);
        int skipCurrent = robHouses(nums, index + 1, robbedFirst, n);

        // �� ū �ݾ��� �޸��ϰ� ��ȯ
        memo[index][robbedFirst] = max(robCurrent, skipCurrent);
        return memo[index][robbedFirst];
    }

    int rob(vector<int>& nums) {
        memset(memo, -1, sizeof(memo)); // �޸������̼� �迭 �ʱ�ȭ
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(robHouses(nums, 0, true, n - 1), // ù ���� �� ���
            robHouses(nums, 1, false, n)); // ������ ���� �� ���
    }
};
