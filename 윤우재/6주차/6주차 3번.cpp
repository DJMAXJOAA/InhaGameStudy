class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //inplace로 하라고?
        //전치행렬로 바꾼다음에, 각 행들을 뒤집으면 됨
        int size = matrix.size();
        for (int i = 0; i < size; i++)
            for (int j = i; j < size; j++)
                swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < size; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};