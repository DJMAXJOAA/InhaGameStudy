// top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for(auto& n : nums)
        {
            m[n]++;
        }

        vector<vector<int>> v(10001, vector<int>(0));

        for(auto& p : m)
        {
            int num = p.first;
            int cnt = p.second;

            v[cnt].push_back(num);
        }

        vector<int> ret;
        for(int i=10000; i>=0; i--)
        {
            vector<int>& cur = v[i];
            while(ret.size() < k && !cur.empty())
            {
                ret.push_back(cur.back());
                cur.pop_back();
            }
        }

        return ret;
    }
};