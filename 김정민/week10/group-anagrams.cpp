class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> M;

        for(int i=0; i<strs.size(); i++) {
            vector<int> vis(27, 0);
            string cur = strs[i];

            for(int j=0; j<cur.size(); j++) {
                vis[cur[j]-'a']++;
            }

            string key = "";
            for(int j=0; j<vis.size(); j++) {
                if(vis[j] == 0) continue;
                char alpha = 'a'+ j;

                key += alpha;
                key += to_string(vis[j]);
            }
            
            M[key].push_back(cur);
        }

        for(auto iter = M.begin(); iter != M.end(); iter++) {
            ans.push_back(iter->second);
        }

        return ans;
    }
};