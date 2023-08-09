//Time taken : 1 hr 18 m 23 s
//Runtime 23ms
//Beats 67.19 % of users with C++
//Memory 16.28mb
//Beats 5.25 % of users with C++

[3주차 2번] / Course Schedule / 1시간18분 / https://leetcode.com/problems/course-schedule/
검색 해봐서 무한 사이클이 도는지 확인하는 문제
1. 중복 체크용 set<int>, 탐색용 multimap<int, int>
2. 반복자의 first 값부터 검색을 시작해서, 무한반복 되지 않으면 넘어가고, 완료한 부분은 삭제
3. 만약 중복되는 수가 들어감 (map 검색이 무한 반복돔) = return false (반복자의 second값을 set에 넣는데, 이미 set에 있으면 return false)

개선 사항
1. 사이클 판별 : 계속 map을 반복하면서 검색하게 되는데, 각 노드마다 사이클을 찾으려고 하니까 비효율적이다
2. 그래프 탐색 문제 -> 인접 노드를 확인할 수 있는 list나 vector를 사용하는게 좋을 듯 하다
3. DFS나 BFS로 푸는게 정배다 (그래프 탐색에 효율적인 방법들)
4. 그 외에도 위상 정렬을 사용하면 더 효율적으로 풀 수 있다고 한다


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