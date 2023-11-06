class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for (int i = 0; i < n - 2; i++) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                if (nums[i] + nums[low] + nums[high] < 0) {
                    low++;
                }
                else if (nums[i] + nums[low] + nums[high] > 0) {
                    high--;
                }
                else {
                    set.insert({ nums[i], nums[low], nums[high] });
                    low++;
                    high--;
                }
            }
        }
        for (auto it : set) {
            output.push_back(it);
        }
        return output;
    }
    // vector<vector<int>> threeSum(vector<int>& nums) 
    // {
    //     sort(nums.begin(),nums.end(),less<int>());
    //     vector<vector<int>> ans;
    //     map<int,int> data;

    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         if(data[nums[i]])
    //         {
    //             data[nums[i]]++;
    //         }

    //         else
    //         {
    //             data[nums[i]] = 1;
    //         }
    //     }

    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         vector<int> temp;
    //         temp.push_back(nums[i]);

    //         for(int j = i+1; j < nums.size(); j++)
    //         {
    //             if(data[-(nums[i]+nums[j])])
    //             {
    //                 if(-(nums[i]+nums[j]) == nums[j] || -(nums[i]+nums[j]) == nums[i])
    //                 {
    //                     if(data[nums[j]] > 1)
    //                     {
    //                         if(nums[j]==0)
    //                         {
    //                             int n = 0;
    //                             for(int k = 0; k < nums.size(); k++)
    //                             {
    //                                 if(nums[k]==0) n++;
    //                             }

    //                             if(n<3) break;

    //                             temp.push_back(nums[j]);
    //                             temp.push_back(nums[j]);

    //                             sort(temp.begin(),temp.end(),less<int>());

    //                             bool different = true;
    //                             for(int k = 0; k < ans.size(); k++)
    //                             {
    //                                 if(temp==ans[k]) different = false;
    //                             }

    //                             if(different)
    //                                 ans.push_back(temp);
    //                             break;
    //                         }

    //                         else
    //                         {
    //                             temp.push_back(nums[j]);
    //                             temp.push_back(nums[j]);

    //                             sort(temp.begin(),temp.end(),less<int>());

    //                             bool different = true;
    //                             for(int k = 0; k < ans.size(); k++)
    //                             {
    //                                 if(temp==ans[k]) different = false;
    //                             }

    //                             if(different)
    //                                 ans.push_back(temp);
    //                             break;
    //                         }

    //                     }

    //                 }

    //                 else
    //                 {
    //                     temp.push_back(nums[j]);
    //                     temp.push_back(-(nums[i]+nums[j]));

    //                     sort(temp.begin(),temp.end(),less<int>());

    //                     bool different = true;
    //                     for(int k = 0; k < ans.size(); k++)
    //                     {
    //                         if(temp==ans[k]) different = false;
    //                     }

    //                     if(different)
    //                         ans.push_back(temp);

    //                     break;
    //                 }
    //             }
    //         }
    //     }

    //     return ans;
    // }
};