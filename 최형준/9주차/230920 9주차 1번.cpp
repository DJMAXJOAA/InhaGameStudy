[9���� 1��] / Valid Anagram / 7�� / https://leetcode.com/problems/valid-anagram/

[���� ����]
��� �˰��� = �ؽ� (�迭)
1. �ƽ�Ű �ڵ� ũ�⿡ �´� int �迭 ����
2. string s�� ���������� ���鼭 ���ڿ� �´� �� �迭�� ���� �ø�
3. string t�� ���������� ���鼭 ���ڿ� �´� �� �迭�� ���� ����
4. �迭�� ���� 0�̸� true

[������]
1. �迭�� ũ�Ⱑ �������� 123�� �����ϴ�, ������� �ʴ� ������� ����

[�ٸ� Ǯ�� ���]
1. �ؽ� ��(unordered_map)
2. ����

Time taken : 7 m 1 s
Runtime 4ms
Beats 86.94 % of users with C++
Memory 7.82MB
Beats 6.49 % of users with C++

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        vector<int> arr(123, 0);

        for (auto v : s)
        {
            arr[v]++;
        }

        for (auto v : t)
        {
            arr[v]--;
        }

        for (auto v : arr)
        {
            if (v != 0)
                return false;
        }

        return true;
    }
};

[�ٸ� Ǯ�� ���]
1. �ؽ� ��(unordered_map)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        for (auto x : s)
        {
            count[x]++;
        }

        for (auto x : t)
        {
            count[x]--;
        }

        for (auto x : count)
        {
            if (x.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};

2. ����
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};