class Solution {
public:
    int countSubstrings(string s) {
        
        int answer = 0;
        int size = s.size();

        for(int i = 0; i < size; i++)
        {
            // 홀수
            int left = i;
            int right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                answer++;
                left--;
                right++;
            }

            // 짝수
            left = i;
            right = i+1;
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                answer++;
                left--;
                right++;
            }
        }

        return answer;
    }
};
