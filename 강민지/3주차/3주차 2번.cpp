class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // 위상정렬
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int> ans;

        for(auto x: prerequisites)
        {
            adj[x[0]].push_back(x[1]); // adj 배열에 adj[0] = 1, adj[1] = 0과 같이 담음
            indegree[x[1]]++;          //  prerequisites[][1]값의 개수 체크 (선수강해야하는 번호)
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            auto t = q.front();
            ans.push_back(t);
            q.pop();

            for(auto x : adj[t])
            {
                indegree[x]--; // prerequisites[][0] 있는 숫자를 줄임으로써 1->0으로 될때를 체크
                if(indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }

        return ans.size()==numCourses;
    }
};
