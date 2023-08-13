class Solution {

public:
    vector<vector<int>> graph;
    vector<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //방향성 있는 그래프 생성
        graph.resize(numCourses);
        visited.assign(numCourses,0);
        for(auto e : prerequisites)
        {   
            //if(e[0] == e[1])return false;
            graph[e[0]].push_back(e[1]);
        }
        //그래프 탐색하며 만일 순회하게되면 return false, 전부 탐색했다면 return true;

        for(int i = 0; i<numCourses;i++)
        {
            if(!visited[i])
                if(!dfs(i)) return 0;
        }
        return 1;
    }

    bool dfs(int idx)
    {
        if(visited[idx] == 1)
            return 0;
        if(visited[idx] == 2)
            return 1;
        
        visited[idx] = 1;
        for(auto e : graph[idx])
        {
            if(!dfs(e))
                return 0;
        }
        visited[idx] = 2;
        return 1;
    }
};