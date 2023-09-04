// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lower(vector<int>& v, int target)
    {
        int st = -1;
        int en = v.size();

        while(st + 1 < en)
        {
            int mid = (st + en) / 2;

            if(v[mid] < target)
            {
                st = mid;
            }
            else
            {
                en = mid;
            }
        }

        return en;
    }

    int lengthOfLIS(vector<int>& nums) {
        int ret = 0;
        vector<int> v;

        for(int i=0; i<nums.size(); i++)
        {
            int cur = nums[i];

            if(v.empty() || v.back() < cur)
            {
                v.push_back(cur);
                continue;
            }

            v[lower(v, cur)] = cur;
        }

        return v.size();
    }
};
