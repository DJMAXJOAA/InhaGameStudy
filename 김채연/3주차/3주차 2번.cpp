// Q2. Course Schedule
//������ prerequisites, course �� �־����� ������ �������� ���θ� ���� ����.
// 
// **ex) [0,1] 0��° ������ �����ϱ� ���� 1��° ������ ���� �����ؾ��Ѵ�.
// *������ ������ ��ȯ�����̸� false
// 
// ����������Ʈ�� ����Ѵ�(����ũ)
// �� ���ϰ� Ŭ����Ǹ� ��������.
// 
//BFS �� ����,
//�Է��� ���� �־��� �迭�� ���ͷ� �ٽ� ������ �Ͽ���.
//<course1, prereauisite1, prerequisite2....>
//<course2, prerequisiet1, ....>
//-> BFS�� ����ϱ� ���ؼ�
//
//�Է��� ���� �־��� course���� BFS�� ������ �������� Ȯ���Ͽ���.

//���� �浵 �𸣰���.

//class Solution {
//public:
//	bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
//		
//		//vector<vector<int> > courses; //���� �ϴ� ����� ���̼����� ����
//		//vector<bool> check(numCourses, false);
//
//		vector<int>* courses = new vector<int>[numCourses + 1];
//		bool* check = new bool[sizeof(bool)* numCourses + 1];
//
//		for (int i = 0; i < prerequisites.size(); i++)
//		{
//			courses[prerequisites[i][0]].push_back(prerequisites[i][1]); // courses�� ���̼������ �־��ֱ�.
//		}
//
//		for (int i = 0; i < numCourses; i++)
//		{
//			if (courses[i].size() == 0)
//				continue; //���̼� ���� ������ �н�
//			else
//			{
//				//fill �Լ� : void fill(ForwardIterator first, ForwardIterator last, const T& val);
//				// -> first : ä����� �ϴ� �ڷᱸ���� ������ġ, last : ����ġ, last�� ����x, val : ä������ϴ� ��.
//
//				fill(check, check + numCourses + 1, false);// check���� 1���� numCorses���� false�� ä���.
//				queue<int> q;
//				q.push(i); // q���� �ε��� �ֱ�?
//				check[i] = true; //check�� i��°�� true�� �����?
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
		if (path[course])//���� ������ �ְ� �̹� ��������
			return false;
		path[course] = 1; //�� ���Դ�?

		vector<int>& v = adj[course];
		//������ ����� üũ
		for (int c:v)
		{
			//�̹� �Ǿ����� ������ �ʿ� x
			if (!mask[c])
				continue;
			if (check(adj, mask, path, c) == false) //�ѹ��̶� false�� ���ϵǸ� false
				return false;
		}

		//����������, end
		path[course] = 0;
		mask[course] = 0;
		return true;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> mask(numCourses); // numCourses�� �ִ밪 10���̶� �迭��밡��.
		vector<int> path(numCourses);
		vector<int> adj[numCourses]; //�����ϴ� ��, ������ Ÿ��

		for (vector<int>& v : prerequisites)
		{
			mask[v[0]] = 1; //1�� �����
			adj[v[0]].push_back(v[1]); //�� �߰�.
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (!mask[i])
				continue;

			if (check(adj, mask, path, i) == false) //���ݺ��°� i
				return false;

		}

		return true;
	}
};


