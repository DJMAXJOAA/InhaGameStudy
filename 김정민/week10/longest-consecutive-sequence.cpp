class Solution {
public:
    int INF = INT_MIN;
    int vis[1000005];

    int dfs(vector<int>& nums, vector<int>& nxt, int depth, int st) {
        if(nxt[st] == INF) {
            return vis[st] = depth;
        }

        if(vis[nxt[st]] != INF) {
            return vis[nxt[st]] + depth;
        }

        return vis[st] = dfs(nums, nxt, depth+1, nxt[st]);
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> M;

        for(int i=0; i<nums.size(); i++) {
            if(M.find (nums[i]) == M.end()) {
                M[nums[i]] = i;
            }
        }

        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            int cnt = 0;
            int num = nums[i];
            if(M.count(num - 1)) continue;

            while(M.count(num++)) cnt++;

            ans = max(ans, cnt);
        }

        return ans;
    }
};

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> S;
//         for(int num : nums) S.insert(num);
        
//         int ans = 0;
//         for(int num : nums) {
//             if(S.count(num-1)) continue;
            
//             int seq = num;
//             int cnt = 0;
//             while(S.count(seq++)) cnt++;
//             ans = max(ans, cnt);
//         }
        
//         return ans;
//     }
// };