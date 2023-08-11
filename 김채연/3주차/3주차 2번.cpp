// Q2. Course Schedule
//문제에 prerequisites, course 가 주어지고 수강이 가능한지 여부를 묻는 문제.
// 
// **ex) [0,1] 0번째 과목을 수강하기 위해 1번째 과목을 먼저 수강해야한다.
// *선수강 과정이 순환과정이면 false
// 
// 선수강리스트를 고려한다(마스크)
// 다 비교하고 클리어가되면 수강가능.
// 
//BFS 를 통해,
//입력을 통해 주어진 배열을 벡터로 다시 재정의 하였다.
//<course1, prereauisite1, prerequisite2....>
//<course2, prerequisiet1, ....>
//-> BFS를 사용하기 위해서
//
//입력을 통해 주어진 course들을 BFS로 수강이 가능한지 확인하였다.

//문제 뜻도 모르겠음.

//class Solution {
//public:
//	bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
//		
//		//vector<vector<int> > courses; //들어야 하는 과목들 선이수과목 정리
//		//vector<bool> check(numCourses, false);
//
//		vector<int>* courses = new vector<int>[numCourses + 1];
//		bool* check = new bool[sizeof(bool)* numCourses + 1];
//
//		for (int i = 0; i < prerequisites.size(); i++)
//		{
//			courses[prerequisites[i][0]].push_back(prerequisites[i][1]); // courses에 선이수과목들 넣어주기.
//		}
//
//		for (int i = 0; i < numCourses; i++)
//		{
//			if (courses[i].size() == 0)
//				continue; //선이수 과목 없으면 패스
//			else
//			{
//				//fill 함수 : void fill(ForwardIterator first, ForwardIterator last, const T& val);
//				// -> first : 채우고자 하는 자료구조의 시작위치, last : 끝위치, last는 포함x, val : 채우고자하는 값.
//
//				fill(check, check + numCourses + 1, false);// check에다 1부터 numCorses까지 false로 채우기.
//				queue<int> q;
//				q.push(i); // q에다 인덱스 넣기?
//				check[i] = true; //check의 i번째를 true로 만들기?
//
//				while (!q.empty())
//				{
//					int x = q.front();
//					q.pop();
//
//					for (int j = 0; j < courses[x].size(); j++)
//					{
//						int temp = courses[x][i];
//
//						if (courses[temp].size() == 0)
//							continue;
//						if (!check[courses[x][j]])
//						{
//							q.push(courses[x][j]);
//							check[courses[x][j]] = true;
//						}
//						if (courses[x][j] == i)
//							return false;
//					}
//				}
//
//
//
//			}
//		}
//		return true;
//	}
//};

class Solution {
public:
	bool check(vector<int> adj[], vector<int> &mask, vector<int>& path, int course)
	{
		if (path[course])//지금 봐야할 애가 이미 들어와있음
			return false;
		path[course] = 1; //다 들어왔다?

		vector<int>& v = adj[course];
		//선수강 과목들 체크
		for (int c:v)
		{
			//이미 되어있음 선수강 필요 x
			if (!mask[c])
				continue;
			if (check(adj, mask, path, c) == false) //한번이라도 false가 리턴되면 false
				return false;
		}

		//빠져나갈때, end
		path[course] = 0;
		mask[course] = 0;
		return true;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> mask(numCourses); // numCourses의 최대값 10만이라 배열사용가능.
		vector<int> path(numCourses);
		vector<int> adj[numCourses]; //인접하는 것, 포인터 타입

		for (vector<int>& v : prerequisites)
		{
			mask[v[0]] = 1; //1로 만들고
			adj[v[0]].push_back(v[1]); //다 추가.
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (!mask[i])
				continue;

			if (check(adj, mask, path, i) == false) //지금보는게 i
				return false;

		}

		return true;
	}
};


