//Longest Increasing Subsequence
//DP ����
//LIS�� �տ������� "�ڷ�" ���ڸ� �����ϸ� 
//�κ� ������ ������ ���� �� "�����ϴ�" ������� ���ڸ� ���鼭 
//�� �κ� ������ ���̰� "�ִ� ����"�� �ǵ��� ���ڸ� �����ϴ� ����Դϴ�.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> dp;
        vector<int> arr;

        for (int i = 0; i < nums.size(); i++)
        {
            if (dp[i] == 0)dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                {
                    if (dp[i] < dp[j] + 1)  // i ���� ū ���� j�� ���� ���.
                    {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        return dp.size();

    }
};