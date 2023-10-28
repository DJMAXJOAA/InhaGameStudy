class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int answer = INT_MIN;
        int start = 1;

        for(int i=0; i<nums.size(); i++)
        {
          start *= nums[i];
          answer = max(start, answer);

          if(start == 0)
           start = 1;
        }

        start = 1;

        for(int i=nums.size()-1; i>=0; i--)
        {
          start *= nums[i];
          answer = max(start, answer);

          if(start == 0)
           start = 1;
        }
        
        return answer;
    }
};
