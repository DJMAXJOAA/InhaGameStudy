[9���� 1��] / Valid Anagram / 7�� / https://leetcode.com/problems/valid-anagram/

[���� ����]
��� �˰��� = �迭 ��ȸ
1. �ƽ�Ű �ڵ� ũ�⿡ �´� int �迭 ����
2. string s�� ���������� ���鼭 ���ڿ� �´� �� �迭�� ���� �ø�
3. string t�� ���������� ���鼭 ���ڿ� �´� �� �迭�� ���� ����
4. �迭�� ���� 0�̸� true

[������]
1. �迭�� ũ�Ⱑ �������� 123�� �����ϴ�, ������� �ʴ� ������� ����

[�ٸ� Ǯ�� ���]
1. �ؽ� Ʈ�� (ü�̴�) -> ���� �߰�

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