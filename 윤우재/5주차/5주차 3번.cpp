class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp? stack?
        //dp가 맞나보네
        
        nums.insert(nums.begin(),0);
        
        vector<int> dp(nums.size(),0);
        for(int i = 1; i<nums.size();i++)
        {
            int maxIdx = 0;
            for(int j = 0; j<i;j++)
            {
                if(nums[j]<nums[i] && dp[j]>dp[maxIdx])
                    maxIdx = j;
            }
            dp[i] = dp[maxIdx]+1;
        }
        int max = dp[0];
        for(auto e : dp)
        {
            cout<<e<<" ";
            if(e>max)
               max = e;
        }
        return max;
    }
};