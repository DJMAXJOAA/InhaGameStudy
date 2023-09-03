[6주차 4번] / Minimum Window Substring / 2시간 23분 / https://leetcode.com/problems/minimum-window-substring/

[문제 접근]
사용 알고리즘 = 슬라이딩 윈도우
1.  문자 크기 수 128 크기의 vector<int> check = 현재 문자열 체크, tCount = t 문자열 문자종류들 체크
2.  문자열을 최초 순회시, end값만 늘려가면서 슬라이딩 윈도우 크기를 확정짓는다
3.  이후 start와 end값을 조절하며 범위를 수정 -> 어디까지 자를수 있는지 가능한지 체크

[개선점]
1.  변수 이름을 확실하게 짓기 -> 근데 뭐라고 지어야할지 잘 안떠올랐음
2.  vector<int> 부분을 unordered_map으로 구성해도 가능하다 (근데 규모가 커지게 되면 비효율적일수도 있음)
3.  슬라이딩 윈도우 전에도 나왔었는데, 제대로 다시 공부해야 할듯. 어려움

[다른 풀이 방법]
1.  일단 최선의 방법은 슬라이딩 윈도우를 사용하는 것이 맞음
2.  브루트 포스나 동적 프로그래밍으로도 풀이는 가능하지만, 비효율적이다.
    브루트 포스는 O(N^2 * M), 동적 프로그래밍은 O(N * M)
3.  일단 슬라이딩 윈도우 문제니까, 다른 풀이는 패스

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

        // 슬라이딩 윈도우 범위
        int start = 0, end = 0, minLen = INT_MAX;
        int minStart = 0; // 최소 길이 윈도우의 시작 인덱스

        // check배열 크기 초기화
        for (int i = 0; i < t.length(); i++)
        {
            tCount[t[i]]++;
        }

        int count = t.size();  // t 문자열의 문자 사이즈
        while (end < s.length())
        {
            // 문자열 t의 문자 종류가 맞으면, 배열에 값 추가
            if (tCount[s[end]] > 0)
            {
                count--;
            }

            // 특정 문자의 나온 횟수를 1 줄임
            tCount[s[end]]--;

            while (count == 0)
            {
                // 원래 있던 범위보다 작으면, 자를 범위를 수정
                if (end - start < minLen)
                {
                    minLen = end - start;
                    minStart = start; 
                    // 원래 여기서 매순간 잘랐는데, 마지막 테스트케이스에서 메모리 오류뜸
                    // 마지막에 한번만 잘라줌
                }

                // start가 늘어나니까 다시 원상복귀
                tCount[s[start]]++;
                if (tCount[s[start]] > 0)
                {
                    count++;
                }

                // 시작값을 늘려서 범위를 줄여줌 -> 어디까지가 한계인가 체크
                start++;
            }

            end++;      // 첫 시작점 0~0부터 -> 문자열 일치할 때까지 end를 늘림
        }

        // 조건 안걸렸으면 빈 문자열로 반환, 나머지는 잘라서 반환
        if (minLen == INT_MAX) return "";
        else return s.substr(minStart, minLen + 1);
    }
};