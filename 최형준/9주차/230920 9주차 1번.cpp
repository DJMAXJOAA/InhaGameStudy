[9주차 1번] / Valid Anagram / 7분 / https://leetcode.com/problems/valid-anagram/

[문제 접근]
사용 알고리즘 = 해시 (배열)
1. 아스키 코드 크기에 맞는 int 배열 선언
2. string s를 마지막까지 돌면서 문자에 맞는 값 배열의 값을 올림
3. string t를 마지막까지 돌면서 문자에 맞는 값 배열의 값을 내림
4. 배열의 값이 0이면 true

[개선점]
1. 배열의 크기가 고정으로 123을 선언하니, 사용하지 않는 빈공간이 존재

[다른 풀이 방법]
1. 해시 맵(unordered_map)
2. 정렬

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

[다른 풀이 방법]
1. 해시 맵(unordered_map)
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

2. 정렬
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};