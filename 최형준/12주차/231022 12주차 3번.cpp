[12���� 3��] / Valid Palindrome / 11�� / https://leetcode.com/problems/valid-palindrome/description/

[���� ����]
��� �˰��� = �� ������ O(n), O(n)
1. string s ���ڿ����� �ҹ��ڷθ� �Ǿ��ִ� ���ο� string temp�� ���
2. �� ó�� ������ start, �� �� ������ end�� ���ϸ鼭 ��� ��ȯ

[������]
1. �߰����� string temp ��� ���� s ���ڿ��� �ٷ� ���ϸ� �������⵵�� ������ �� ����

[�ٸ� Ǯ�� ���]
1. �� ������ O(n), O(1)
2. ���ڿ��� ����� ���ϱ� O(n), O(n)

Time taken : 11 m 26 s
Runtime 5ms
Beats 48.11 % of users with C++
Memory 7.94MB
Beats 18.49 % of users with C++

class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9'))
            {
                temp += s[i];
            }
            else if ('A' <= s[i] && s[i] <= 'Z')
            {
                temp += s[i] + 32;
            }
        }

        cout << temp;
        int size = temp.size();
        int start = 0;
        int end = size - 1;
        for (int i = 0; i < (size + 1) / 2; i++)
        {
            if (temp[start] != temp[end])
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};

[�ٸ� Ǯ�� ���]
�� ������ O(n), O(1)
1. start �� end �������� ���� ������ �ҹ��ڳ� ���ڰ� ���ö����� �����Ͽ� ��

bool isPalindrome(string s) {
    int start = 0, end = s.size() - 1;
    while (start < end) {
        while (start < end && !isalnum(s[start])) start++;
        while (start < end && !isalnum(s[end])) end--;
        if (tolower(s[start]) != tolower(s[end])) return false;
        start++; end--;
    }
    return true;
}

���ڿ��� ����� ���ϱ� O(n), O(n)
1. �߰� ���ڿ� string temp
2. temp ���ڿ��� ������ rev ���ڿ�
3. temp == rev���� üũ

bool isPalindrome(string s) {
    string temp = "";
    for (char c : s) {
        if (isalnum(c)) temp += tolower(c);
    }
    string rev = temp;
    reverse(rev.begin(), rev.end());
    return temp == rev;
}
