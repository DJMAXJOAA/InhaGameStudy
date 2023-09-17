class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();

        vector<int> answer(size, 1);

      //Prefix Product Array and Suffix Product Array 
        int temp = 1;
        for(int i = 0; i < size; i++)
        {
            answer[i] *= temp;
            temp *= nums[i]; 
        }

        temp = 1;
         for(int i = size - 1; i >= 0; i--)
        {
            answer[i] *= temp;
            temp *= nums[i]; 
        }

        return answer;
    }
};
