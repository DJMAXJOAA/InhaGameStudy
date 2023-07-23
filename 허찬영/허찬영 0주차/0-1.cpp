class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int a = target % 2;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] )
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int left = 0;
        int right = temp.size() - 1;
        while(left < right)
        {
            int sum = temp[left] + temp[right];
            if(sum == target)
                break;
            else if(sum > target)
                right--;
            else
                left++;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(temp[left] == nums[i])
                ans.push_back(i);
            else if(temp[right] == nums[i])
                ans.push_back(i);

            if(ans.size() == 2)
                break;
        }
        return ans;
    }
};
