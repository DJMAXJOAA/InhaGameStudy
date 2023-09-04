class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();

        // 90도로 뒤집기.
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 180도로 뒤집기
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N / 2; ++j) {
                swap(matrix[i][j], matrix[i][N - j - 1]);
            }
        }
    }
};