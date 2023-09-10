class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int size = nums.size() + 1;
        vector<int> countingNum(size, 0);
        int answer;

        for(int i = 0; i < nums.size(); i++)
        {
            countingNum[nums[i]]++;
        }

        for(int i = 0; i < countingNum.size(); i++)
        {
            if(countingNum[i] == 0) answer = i;
        }

        return answer;

    }
};
