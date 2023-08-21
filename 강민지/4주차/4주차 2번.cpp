class Solution {
public:
    int characterReplacement(string s, int k) {
        
        if (s.size() == 0) return 0;

        vector <int> arr(128);

        int j = 0, largestCount = 0;

        for (int i = 0; i < s.size(); i++) 
        {
            // 알파벳 카운트, 최대 연속 숫자 갱신
            largestCount = max(largestCount, ++arr[s[i]]);    

            if (i - j + 1 - largestCount > k)
                arr[s[j++]]--;
        }

        return s.length() - j;

    }
};
