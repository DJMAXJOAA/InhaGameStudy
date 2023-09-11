class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> answer(size, 1);

        int temp = 1;
        for (int i = 1; i < size; i++)
        {
            temp *= nums[i - 1];
            answer[i] = temp;
        }

        temp = 1;
        for (int j = size - 2; j > -1; j--)
        {
            temp *= nums[j + 1];
            answer[j] *= temp;
        }

        return answer;
    }
};