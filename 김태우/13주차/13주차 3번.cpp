class Solution {
public:
    int robOriginal(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2);

        if (n == 1) return nums[0];
        else if (n == 2) return max(nums[0], nums[1]);
        dp[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = nums[i] + max(dp[i + 2], dp[i + 3]);
        }

        return max(dp[0], dp[1]);
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        // exclude first
        vector<int> numsA(nums.begin() + 1, nums.end());

        //exclude last
        vector<int> numsB(nums.begin(), nums.end() - 1);

        return max(robOriginal(numsA), robOriginal(numsB));
    }

    // int rob(vector<int>& nums)
    // {
    //     int n = nums.size();

    //     if(n==1) return nums[0];
    //     else if(n==2) return max(nums[0],nums[1]);

    //     vector<int> dp(n+2);
    //     dp[n+1] = 0;
    //     dp[n] = 0;
    //     dp[n-1] = nums[n-1];

    //     for(int i = n-2; i>=0; i--)
    //     {
    //         dp[i] = nums[i];

    //         if(i+2==n-1)
    //         {
    //             if(i%2)
    //             {
    //                 dp[i]+= max(dp[i+2],dp[i+3]);
    //             }

    //             else
    //             {
    //                 dp[i]+=dp[i+3];
    //                 dp[i] = max(dp[i],dp[i+2]);
    //             }

    //         }

    //         else if(i+3==n-1)
    //         {
    //             if(i%2)
    //             {
    //                 dp[i]+= max(dp[i+2],dp[i+3]);
    //             }

    //             else
    //             {
    //                 dp[i]+=dp[i+2];
    //                 dp[i] = max(dp[i],dp[i+3]);
    //             }
    //         }

    //         else
    //         {
    //             dp[i]+= max(dp[i+2],dp[i+3]);
    //         }
    //     }

    //     return max(dp[0],dp[1]);
    // }
};