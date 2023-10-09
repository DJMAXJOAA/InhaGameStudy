[10주차 4번] / Group Anagrams / 33분 / https://leetcode.com/problems/group-anagrams/description/

[문제 접근]
사용 알고리즘 = 정렬 후 인덱스 비교 :: O(m * n log n), O(m * n)
1. strs를 정렬시켜놓은 같은 크기의 배열 선언 후 초기화
2. result의 배열과 string 비교

[개선점]
1. 해시 테이블을 사용하면 중복 비교를 피할 수 있어서 시간 복잡도를 시킬 수 있음

[다른 풀이 방법]
1. 해시 테이블 (unordered_map) : O(m * n log n), O(m* n)

Time taken : 33 m 18 s
Runtime 2821ms
Beats 5.01 % of users with C++
Memory 44.17MB
Beats 5.01 % of users with C++

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<int> resultIndex;
        if (strs.size() == 0)
        {
            return result;
        }

        int i, j;
        vector<string> sortedStrs;
        for (i = 0; i < strs.size(); i++)
        {
            string sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end());
            sortedStrs.push_back(sortedString);
        }

        {
            vector<string> temp = { strs[0] };
            result.push_back(temp);
            resultIndex.push_back(0);
        }

        for (i = 1; i < strs.size(); i++)
        {
            for (j = 0; j < result.size(); j++)
            {
                string temp1 = sortedStrs[i];
                string temp2 = sortedStrs[resultIndex[j]];

                if (temp1 == temp2)
                {
                    result[j].push_back(strs[i]);
                    break;
                }
            }
            if (j == result.size())
            {
                vector<string> temp = { strs[i] };
                result.push_back(temp);
                resultIndex.push_back(i);
            }
        }

        return result;
    }
};

[다른 풀이 방법]
1. unordered_map

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (const auto& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& pair : map) {
            result.push_back(pair.second);
        }
        return result;
    }
};
