[9���� 3��] / Maximum Subarray / 33�� / https://leetcode.com/problems/maximum-subarray/

[���� ����]
��� �˰��� = DP(���� ���α׷���, ī���� �˰��� :: �������� �κ� �迭�� �ִ� ��)
1. dp�迭 vector<int> ����
2. nums �迭�� ���鼭 ���� nums[i]�� ���� dp�迭���� ���� nums[i]�� �ִ밪 ��
3. result�� ���� dp�迭 �ִ밪 ��

[�ð� ���⵵] 
O(n) : �迭 �ѹ� ��ȸ
[���� ���⵵] 
O(n) : numsũ���� dp �迭

[������]
1. dp �迭�� ũ�⸦ nums �迭�� �����ϰ� �� �ʿ䰡 ���� (������ ���� ���� ���� ���� ����ϴϱ�, ũ�Ⱑ 2�� �迭�̸� ����ϴ�)

[�ٸ� Ǯ�� ���]
1. ���� ����

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


[�ٸ� Ǯ�� ���]
���� ���� :: O(n log n)
1. ���� : �߾� ��ġ���� �迭�� �� ���� ����
2. ���� : ������ �迭���� �ִ� �κ� �迭 �հ踦 ã�´�. ���� �� ��迡 ���� �ִ� �κ� �迭�� �հ踦 ã�� �� �� ���� ū ���� ����
4. ���� : ū ������ ���ļ� �ִ� �հ� ã��

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }

private:
    int maxSubArray(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];  // �⺻ ���: �迭�� �ϳ��� ��Ҹ� �ִ� ���

        int mid = left + (right - left) / 2;  // �߰� ���� ���

        // ���� �κ� �迭�� ������ �κ� �迭������ �ִ� �հ� ã��
        int leftMax = maxSubArray(nums, left, mid);
        int rightMax = maxSubArray(nums, mid + 1, right);

        // �߾��� ���� �ִ� �κ� �迭�� �ִ� �հ� ã��
        int leftCrossMax = nums[mid], leftCrossSum = 0;
        for (int i = mid; i >= left; i--) {  // �߾ӿ��� �������� Ȯ��
            leftCrossSum += nums[i];
            leftCrossMax = max(leftCrossMax, leftCrossSum);
        }

        int rightCrossMax = nums[mid + 1], rightCrossSum = 0;
        for (int i = mid + 1; i <= right; i++) {  // �߾ӿ��� ���������� Ȯ��
            rightCrossSum += nums[i];
            rightCrossMax = max(rightCrossMax, rightCrossSum);
        }

        // �� ���(���� �ִ�, ������ �ִ�, �߾� ��ģ �ִ�)���� ���� ū ���� ��ȯ
        return max({ leftMax, rightMax, leftCrossMax + rightCrossMax });
    }
};
