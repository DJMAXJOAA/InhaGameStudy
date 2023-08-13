class Solution {
	struct Graph
	{
		vector<vector<int>> adjList;

		Graph(vector<vector<int>> const& edges, int n)
		{
			adjList.resize(n);

			for (int i = 0; i < edges.size(); i++)
			{
				adjList[edges[i][1]].push_back(edges[i][0]);
			}
		}
	};

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// 그래프 생성
		Graph graph(prerequisites, numCourses);

		// 노드가 발견되었는지 여부 추적
		vector<bool> discovered(numCourses);

		// DFS에서 노드의 출발 시간 추적
		vector<int> departure(numCourses);

		int time = 0;

		// 발견되지 않은 모든 노드에서 DFS 순회 수행
		// 그래프의 연결된 모든 구성 요소를 방문
		for (int i = 0; i < numCourses; i++)
		{
			if (!discovered[i])
			{
				DFS(graph, i, discovered, departure, time);
			}
		}

		// 주어진 방향 그래프가 DAG인지 확인
		for (int u = 0; u < numCourses; u++)
		{
			// (u, v)가 백 엣지를 형성하는지 확인
			for (int i = 0; i < graph.adjList[u].size(); i++)
			{
				int v = graph.adjList[u][i];

				// 노드 'v'의 출발 시간이 노드 'u' 출발 시간보다 크거나 같으면 백 엣지를 형성한다.
				// departure[u] <= departure[v] 이면 사이클 형성
				if (departure[u] <= departure[v])
				{
					return false;
				}
			}
		}

		// 사이클 없음
		return true;
	}

	// 그래프의 DFS를 수행하고 모든 노드의 출발 시간을 설정
	void DFS(Graph const& graph, int v, vector<bool>& discovered, vector<int>& departure, int& time)
	{
		// 현재 노드를 발견된 것으로 표시
		discovered[v] = true;

		// 모든 엣지(v, u)에 대해 수행
		for (int i = 0; i < graph.adjList[v].size(); i++)
		{
			int u = graph.adjList[v][i];

			// 'u'가 아직 발견되지 않은 경우
			if (!discovered[u])
			{
				DFS(graph, u, discovered, departure, time);
			}
		}

		// 역추적 준비
		// 노드 'v'의 출발 시간 설정
		departure[v] = time++;
	}
};