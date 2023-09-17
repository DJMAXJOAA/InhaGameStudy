class Solution {
public:
    int bottomup(string text1, string text2) {
        // only need max num, add 1 after the same char fouund => DP
        // check two string => 2D
        // problem with inital num, compare index out of bound (to preserve formula)
       // -> bottom up with add zero matirx
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        for (int i = text1.length() - 1; i >= 0; i--) {
            for (int j = text2.length() - 1; j >= 0; j--) {

                int ans;
                if (text1[i] == text2[j])
                    ans = 1 + dp[i + 1][j + 1];
                else
                    ans = max(dp[i][j + 1], dp[i + 1][j]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return bottomup(text1, text2);
    }
};

// class Solution 
// {
// public:
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         // top down way
//         int m  = text1.size();
//         int n = text2.size();

//         int matrix[m][n];
//         fill(&matrix[0][0], &matrix[m-1][n], 0);

//         if(text1[0] == text2[0]) matrix[0][0] = 1;

//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(!(i==0 && j == 0))
//                 {
//                     if(text1[i] == text2[j])
//                     {
//                         if(i==0)
//                         {
//                             // problem with smae char
//                             matrix[i][j] = matrix[i][j-1] + 1;
//                         }

//                         else if(j==0)
//                         {
//                             matrix[i][j] = matrix[i-1][j]+1;
//                         }

//                         else
//                         {
//                             matrix[i][j] = matrix[i-1][j-1]+1;
//                         }
//                     }

//                     else
//                     {
//                         if(i==0)
//                         {
//                             matrix[i][j] = matrix[i][j-1];
//                         }

//                         else if(j==0)
//                         {
//                             matrix[i][j] = matrix[i-1][j];
//                         }

//                         else
//                         {
//                             matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j]);
//                         }
//                     }
//                 }
//             }
//         }

//         return matrix[m-1][n-1];
//     }
// };

// class Solution 
// {
// public:
//     int longestCommonSubsequence(string text1, string text2) 
//     {
//         int ans = 0;
//         int temp = 0;
//         int kj = 0;
//         int i,j;

//         for(i = 0; i < text1.size();i++)
//         {
//             for(j = kj; j < text2.size(); j++)
//             {
//                 if(text1[i] == text2[j])
//                 {
//                     temp++;
//                     kj = ++j;
//                     break;
//                 }
//             }

//             // if(j == text2.size())
//             // {
//             //     kj = 0;
//             //     ans = max(ans,temp);
//             // }

//         }

//         return ans;
//     }
// };