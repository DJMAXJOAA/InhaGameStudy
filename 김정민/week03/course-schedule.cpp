// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nodes(numCourses);
        vector<int> pre(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++)
        {
            // bi -> ai
            vector<int> cur = prerequisites[i];
            nodes[cur[1]].push_back(cur[0]);
            pre[cur[0]]++;
        }        

        queue<int> Q;
        for(int i=0; i<numCourses; i++)
        {
            if(pre[i] == 0) 
            {
                Q.push(i);
            }
        }
        
        for(int i=0; i<numCourses; i++)
        {
            if(Q.empty()) return false;
            int cur = Q.front(); Q.pop();

            for(int j=0; j<nodes[cur].size(); j++)
            {
                int nxt = nodes[cur][j];
                pre[nxt]--;
                if(pre[nxt] == 0)
                {
                    Q.push(nxt);
                }
            }
        }

        return true;
    }
};