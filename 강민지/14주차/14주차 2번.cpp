class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> answer;
        map<vector<int>, int> mp;

        int index = 0;
        
        sort(nums.begin(), nums.end());

       for(int i = 0; i < nums.size(); i++)
       {
           if(i > 0 && nums[i] == nums[i-1])    continue; // 같다면 i=0일때 처리됨  

           int left = i+1;
           int right = nums.size()-1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right] ;

                if(sum < 0)
                {
                   left++;
                }
                else if(sum > 0)
                {
                    right--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    answer.push_back(temp);

                    left++;
                    right--;
                  
                    // 중복처리
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
            }
       }
        
               
        return answer;
    }
};
