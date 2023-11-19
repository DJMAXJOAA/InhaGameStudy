#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        bool kMove=false;
        bool jMove=false;
        
        for(int i=0; i<nums.size(); i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k)
            {
                if(i>0)
                {
                    if(nums[i]==nums[i-1])
                        break;
                }
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.insert(temp);
                    j++;
                    k--;
                }
                else if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
            }
        }
        
        vector<vector<int>> output;
        for(auto num3 : ans)
            output.push_back(num3);
        
        return output;
    }
};
