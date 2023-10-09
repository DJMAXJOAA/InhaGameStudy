[10���� 4��] / Group Anagrams / 33�� / https://leetcode.com/problems/group-anagrams/description/

[���� ����]
��� �˰��� = ���� �� �ε��� �� :: O(m * n log n), O(m * n)
1. strs�� ���Ľ��ѳ��� ���� ũ���� �迭 ���� �� �ʱ�ȭ
2. result�� �迭�� string ��

[������]
1. �ؽ� ���̺��� ����ϸ� �ߺ� �񱳸� ���� �� �־ �ð� ���⵵�� ��ų �� ����

[�ٸ� Ǯ�� ���]
1. �ؽ� ���̺� (unordered_map) : O(m * n log n), O(m* n)

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

[�ٸ� Ǯ�� ���]
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
