class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {

        int n = s.size();
        map<int, char> seq;
        map<char, int> m;
        int max = 0;
        int cursor = 0;

        for (int i = 0; i < n; i++)
        {
            if (m.count(s[i])) //같은 문자가 나왔다
            {
                int temp = i - cursor;
                max = (max > temp) ? max : temp;
                cursor = (cursor > m[s[i]] + 1) ? cursor : m[s[i]] + 1;
            }

            seq[i] = s[i];
            m[s[i]] = i;

        }

        int temp = n - cursor;
        max = (max > temp) ? max : temp;

        return max;

    }
};