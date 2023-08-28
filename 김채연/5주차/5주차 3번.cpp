//Longest Increasing Subsequence
//DP 문제
//LIS는 앞에서부터 "뒤로" 숫자를 선택하며 
//부분 수열을 구성해 나갈 때 "증가하는" 순서대로 숫자를 고르면서 
//고른 부분 수열의 길이가 "최대 길이"가 되도록 숫자를 선택하는 경우입니다.

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
                    if (dp[i] < dp[j] + 1)  // i 보다 큰 숫자 j가 있을 경우.
                    {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        return dp.size();

    }
};