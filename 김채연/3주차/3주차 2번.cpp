// Q2. Course Schedule
//������ prerequisites, course �� �־����� ������ �������� ���θ� ���� ����.
// 
// **ex) [0,1] 0��° ������ �����ϱ� ���� 1��° ������ ���� �����ؾ��Ѵ�.
// **numCourse ��ŭ ������ �� ������ true ���ϸ� false
// 
//BFS �� ����,
//�Է��� ���� �־��� �迭�� ���ͷ� �ٽ� ������ �Ͽ���.
//<course1, prereauisite1, prerequisite2....>
//<course2, prerequisiet1, ....>
//-> BFS�� ����ϱ� ���ؼ�
//
//�Է��� ���� �־��� course���� BFS�� ������ �������� Ȯ���Ͽ���.

//���� �浵 �𸣰���.

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
		
		//vector<vector<int> > courses; //���� �ϴ� ����� ���̼����� ����
		//vector<bool> check(numCourses, false);

		vector<int>* courses = new vector<int>[numCourses + 1];
		bool* check = new bool[sizeof(bool* numCourses + 1)];

		for (int i = 0; i < prerequisites.size(); i++)
		{
			courses[prerequisites[i][0]].push_back(prerequisites[i][1]); // courses�� ���̼������ �־��ֱ�.
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (courses[i].size() == 0)
				continue; //���̼� ���� ������ �н�
			else
			{
				//fill �Լ� : void fill(ForwardIterator first, ForwardIterator last, const T& val);
				// -> first : ä����� �ϴ� �ڷᱸ���� ������ġ, last : ����ġ, last�� ����x, val : ä������ϴ� ��.

				fill(check, check + numCourses + 1, false);// check���� 1���� numCorses���� false�� ä���.
				queue<int> q;
				q.push(i); // q���� �ε��� �ֱ�?
				check[i] = true; //check�� i��°�� true�� �����?

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


