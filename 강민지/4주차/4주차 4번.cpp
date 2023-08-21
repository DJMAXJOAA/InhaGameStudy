class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        vector<pair<int, int>> temp;

        for(auto i=mp.begin(); i!=mp.end(); i++)
        {
            temp.push_back({i->second, i->first});
        }

        sort(temp.begin(), temp.end());
        
        vector<int> answer;

        for(int i=0; i<k; i++)
        {
            answer.push_back(temp[temp.size()-1].second);
            temp.pop_back();
        }
      
        return answer;
    }
};
