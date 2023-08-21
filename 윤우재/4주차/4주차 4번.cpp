class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> temp;
        vector<pair<int, int>> answer;

        if(nums.size() == 1)
        {
            temp.push_back(nums[0]);
            return temp;
        }
        sort(nums.begin(), nums.end());
        int cnt = 1;
        for(int i = 1; i<nums.size();i++)
        {
            if(nums[i] == nums[i-1])
            {
                cnt++;
            }
            else
            {
                answer.push_back(make_pair(cnt,nums[i-1]));
                cnt = 1;
            }
        }
        
        answer.push_back(make_pair(cnt,nums.back()));
        sort(answer.rbegin(), answer.rend());
        for(int i = 0; i<k;i++)
        {
            temp.push_back(answer[i].second);
        }
        return temp;
    }
};