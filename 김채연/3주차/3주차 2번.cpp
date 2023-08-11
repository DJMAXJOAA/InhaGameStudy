// Q2. Course Schedule
//문제에 prerequisites, course 가 주어지고 수강이 가능한지 여부를 묻는 문제.
// 
// **ex) [0,1] 0번째 과목을 수강하기 위해 1번째 과목을 먼저 수강해야한다.
// **numCourse 만큼 수강할 수 있으면 true 못하면 false
// 
//BFS 를 통해,
//입력을 통해 주어진 배열을 벡터로 다시 재정의 하였다.
//<course1, prereauisite1, prerequisite2....>
//<course2, prerequisiet1, ....>
//-> BFS를 사용하기 위해서
//
//입력을 통해 주어진 course들을 BFS로 수강이 가능한지 확인하였다.

//문제 뜻도 모르겠음.

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
		
		//vector<vector<int> > courses; //들어야 하는 과목들 선이수과목 정리
		//vector<bool> check(numCourses, false);

		vector<int>* courses = new vector<int>[numCourses + 1];
		bool* check = new bool[sizeof(bool* numCourses + 1)];

		for (int i = 0; i < prerequisites.size(); i++)
		{
			courses[prerequisites[i][0]].push_back(prerequisites[i][1]); // courses에 선이수과목들 넣어주기.
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (courses[i].size() == 0)
				continue; //선이수 과목 없으면 패스
			else
			{
				//fill 함수 : void fill(ForwardIterator first, ForwardIterator last, const T& val);
				// -> first : 채우고자 하는 자료구조의 시작위치, last : 끝위치, last는 포함x, val : 채우고자하는 값.

				fill(check, check + numCourses + 1, false);// check에다 1부터 numCorses까지 false로 채우기.
				queue<int> q;
				q.push(i); // q에다 인덱스 넣기?
				check[i] = true; //check의 i번째를 true로 만들기?

				while (!q.empty())
				{
					int x = q.front();
					q.pop();

					for (int j = 0; j < courses[x].size(); j++)
					{
						int temp = courses[x][i];

						if (courses[temp].size() == 0)
							continue;
						if (!check[courses[x][j]])
						{
							q.push(courses[x][j]);
							check[courses[x][j]] = true;
						}
						if (courses[x][j] == i)
							return false;
					}
				}



			}
		}
		return true;
	}
};


