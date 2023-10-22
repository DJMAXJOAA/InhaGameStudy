[12주차 3번] / Valid Palindrome / 11분 / https://leetcode.com/problems/valid-palindrome/description/

[문제 접근]
사용 알고리즘 = 투 포인터 O(n), O(n)
1. string s 문자열에서 소문자로만 되어있는 새로운 string temp를 사용
2. 맨 처음 포인터 start, 맨 뒤 포인터 end를 비교하면서 결과 반환

[개선점]
1. 추가적인 string temp 사용 없이 s 문자열을 바로 비교하면 공간복잡도를 개선할 수 있음

[다른 풀이 방법]
1. 투 포인터 O(n), O(1)
2. 문자열을 뒤집어서 비교하기 O(n), O(n)

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

[다른 풀이 방법]
투 포인터 O(n), O(1)
1. start 와 end 포인터의 증감 조건을 소문자나 숫자가 나올때까지 제한하여 비교

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

문자열을 뒤집어서 비교하기 O(n), O(n)
1. 추가 문자열 string temp
2. temp 문자열을 뒤집은 rev 문자열
3. temp == rev인지 체크

bool isPalindrome(string s) {
    string temp = "";
    for (char c : s) {
        if (isalnum(c)) temp += tolower(c);
    }
    string rev = temp;
    reverse(rev.begin(), rev.end());
    return temp == rev;
}
