class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> answer;
        answer.push_back(nums[0]);

        for(int i = 0; i < nums.size(); i++)
        {
          // 저장된 숫자보다 추가할 숫자(nums[i])가 더 크면 answer에 바로 추가
            if(nums[i] > answer.back())
                answer.push_back(nums[i]);
          // nums[i] 이상의 숫자의 위치를 찾아서 answer에서 교체
            else
            {
                int index = lower_bound(answer.begin(), answer.end(), nums[i]) - answer.begin();
                answer[index] = nums[i];
            }
        }

        return answer.size();
    }
};
