class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint32_t> cache(target + 1);
        cache[0] = 1; //왜 1로하는 거지?

        for (int i = 1; i <= target; i++)
            for (int j = 0; j < nums.size(); j++)
                if (i - nums[j] >= 0)
                    cache[i] += cache[i - nums[j]];

        return cache[target];
        //buttom-up
    }
};