// Medium
// Longest Common Subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int Cnt = 0;

        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                {
                    Cnt++;
                }
            }
        }

        return Cnt;
    }
};