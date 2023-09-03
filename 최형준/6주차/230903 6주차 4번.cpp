[6���� 4��] / Minimum Window Substring / 2�ð� 23�� / https://leetcode.com/problems/minimum-window-substring/

[���� ����]
��� �˰��� = �����̵� ������
1.  ���� ũ�� �� 128 ũ���� vector<int> check = ���� ���ڿ� üũ, tCount = t ���ڿ� ���������� üũ
2.  ���ڿ��� ���� ��ȸ��, end���� �÷����鼭 �����̵� ������ ũ�⸦ Ȯ�����´�
3.  ���� start�� end���� �����ϸ� ������ ���� -> ������ �ڸ��� �ִ��� �������� üũ

[������]
1.  ���� �̸��� Ȯ���ϰ� ���� -> �ٵ� ����� ��������� �� �ȶ��ö���
2.  vector<int> �κ��� unordered_map���� �����ص� �����ϴ� (�ٵ� �Ը� Ŀ���� �Ǹ� ��ȿ�����ϼ��� ����)
3.  �����̵� ������ ������ ���Ծ��µ�, ����� �ٽ� �����ؾ� �ҵ�. �����

[�ٸ� Ǯ�� ���]
1.  �ϴ� �ּ��� ����� �����̵� �����츦 ����ϴ� ���� ����
2.  ���Ʈ ������ ���� ���α׷������ε� Ǯ�̴� ����������, ��ȿ�����̴�.
    ���Ʈ ������ O(N^2 * M), ���� ���α׷����� O(N * M)
3.  �ϴ� �����̵� ������ �����ϱ�, �ٸ� Ǯ�̴� �н�

Time taken : 2 hrs 23 m 44 s
Runtime 7ms
Beats 91.83 % of users with C++
Memory 8.14MB
Beats 24.16 % of users with C++

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> check(128);
        vector<int> tCount(128);
        string result = {};

        // �����̵� ������ ����
        int start = 0, end = 0, minLen = INT_MAX;
        int minStart = 0; // �ּ� ���� �������� ���� �ε���

        // check�迭 ũ�� �ʱ�ȭ
        for (int i = 0; i < t.length(); i++)
        {
            tCount[t[i]]++;
        }

        int count = t.size();  // t ���ڿ��� ���� ������
        while (end < s.length())
        {
            // ���ڿ� t�� ���� ������ ������, �迭�� �� �߰�
            if (tCount[s[end]] > 0)
            {
                count--;
            }

            // Ư�� ������ ���� Ƚ���� 1 ����
            tCount[s[end]]--;

            while (count == 0)
            {
                // ���� �ִ� �������� ������, �ڸ� ������ ����
                if (end - start < minLen)
                {
                    minLen = end - start;
                    minStart = start; 
                    // ���� ���⼭ �ż��� �߶��µ�, ������ �׽�Ʈ���̽����� �޸� ������
                    // �������� �ѹ��� �߶���
                }

                // start�� �þ�ϱ� �ٽ� ���󺹱�
                tCount[s[start]]++;
                if (tCount[s[start]] > 0)
                {
                    count++;
                }

                // ���۰��� �÷��� ������ �ٿ��� -> �������� �Ѱ��ΰ� üũ
                start++;
            }

            end++;      // ù ������ 0~0���� -> ���ڿ� ��ġ�� ������ end�� �ø�
        }

        // ���� �Ȱɷ����� �� ���ڿ��� ��ȯ, �������� �߶� ��ȯ
        if (minLen == INT_MAX) return "";
        else return s.substr(minStart, minLen + 1);
    }
};