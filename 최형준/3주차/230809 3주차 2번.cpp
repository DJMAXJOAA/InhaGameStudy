//Time taken : 1 hr 18 m 23 s
//Runtime 23ms
//Beats 67.19 % of users with C++
//Memory 16.28mb
//Beats 5.25 % of users with C++

[3���� 2��] / Course Schedule / 1�ð�18�� / https://leetcode.com/problems/course-schedule/
�˻� �غ��� ���� ����Ŭ�� ������ Ȯ���ϴ� ����
1. �ߺ� üũ�� set<int>, Ž���� multimap<int, int>
2. �ݺ����� first ������ �˻��� �����ؼ�, ���ѹݺ� ���� ������ �Ѿ��, �Ϸ��� �κ��� ����
3. ���� �ߺ��Ǵ� ���� �� (map �˻��� ���� �ݺ���) = return false (�ݺ����� second���� set�� �ִµ�, �̹� set�� ������ return false)

���� ����
1. ����Ŭ �Ǻ� : ��� map�� �ݺ��ϸ鼭 �˻��ϰ� �Ǵµ�, �� ��帶�� ����Ŭ�� ã������ �ϴϱ� ��ȿ�����̴�
2. �׷��� Ž�� ���� -> ���� ��带 Ȯ���� �� �ִ� list�� vector�� ����ϴ°� ���� �� �ϴ�
3. DFS�� BFS�� Ǫ�°� ����� (�׷��� Ž���� ȿ������ �����)
4. �� �ܿ��� ���� ������ ����ϸ� �� ȿ�������� Ǯ �� �ִٰ� �Ѵ�


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        set<int> add;
        multimap<int, int> map;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            map.insert(make_pair(prerequisites[i][0], prerequisites[i][1]));
        }

        for (auto iter = map.begin(); iter != map.end(); iter++)
        {
            multimap<int, int>::iterator itr;
            int find_value = iter->first;
            add.insert(find_value);
            if (iter != map.begin())
            {
                map.erase(map.begin());
            }
            while (1)
            {
                itr = map.find(find_value);

                if (itr == map.end())
                    break;

                if (add.find(itr->second) != add.end())
                    return false;
                else
                    add.insert(itr->second);

                find_value = itr->second;
            }
            add.clear();

        }

        return true;
    }
};