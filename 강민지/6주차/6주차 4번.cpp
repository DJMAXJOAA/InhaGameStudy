class Solution {
public:
    string minWindow(string s, string t) {
        
        int m = s.size();
        int n = t.size();
        if (n > m) return ""; // 있는 문자열보다 찾는 문자열이 더 길때

        int map[256] = {0};  // 알파벳 저장할 공간
        for (char c : t)    // t에 있는 알파벳 부분에만 +1을 함
            map[c]++;
        

        int count = 0, left = 0, start = -1, end = -1, ans = INT_MAX; 
        int window[256] = {0};  // 알파벳 빈도수 확인용 배열

        
        for (int right = 0; right < m; right++) 
        {
            window[s[right]]++; 

            if (window[s[right]] <= map[s[right]])
                count++; // t에 있는 문자열을 s에서 찾을 때
            
            if (count == n) // t에 있는 문자열이 모두 포함될 때
            {
                // t에 있는 알파벳이 아니거나, 두번 이상 나온 문자일 경우 left++
                while (map[s[left]] == 0 || window[s[left]] > map[s[left]]) 
                {
                    window[s[left]]--;
                    left++;
                }

                // right - left + 1은 찾은 문자열의 길이, 문자열 길이 갱신하는 부분
                if ((right - left + 1) < ans) 
                {
                    ans = right - left + 1; // 문자열 길이
                    start = left;
                    end = right;
                }

                window[s[left]]--;
                left++;
                count--;
            }
        }

        if (start == -1) return "";  // 문자열이 한번도 찾아지지 않았을 때
        
        string final = "";
        for (int x = start; x <= end; x++) 
            final += s[x]; 
        
        return final;
    }
};
