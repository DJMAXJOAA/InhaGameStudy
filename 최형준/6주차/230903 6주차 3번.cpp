[6���� 3��] / Rotate Image / 37�� / https://leetcode.com/problems/rotate-image/

[���� ����]
��� �˰��� = ť�� �̿��ؼ� �ּҰ��� �ӽ� ����
1. start = 0, end = �迭�� �������κа����� ����
2. insert_queue() �ܰ��� ���� �ּҰ� ����
3. rotate_matrix() �����ߴ� ť�� ���� pop ��Ű�鼭 �ε��� ����
4. start++, end-- �ؼ� ũ�Ⱑ start < end�� �ѹ� ��(������ ��Ʈ������ ����)

[������]
1. ť�� ���� �������� �ʰ� �ٷ� ���ҽ��ѵ� ��
2. �Լ��� �ΰ��� ������ �ʰ�, �ϳ��� �������� ���� �� ����

[�ٸ� Ǯ�� ���]
1. ��ġ ���(Transpose)�� �����ؼ� ���� �޸� ���� ���� �ϳ��� �������� ������

Time taken : 37 m 48 s
Runtime 4ms
Beats 36.93 % of users with C++
Memory 7.10MB
Beats 54.71 % of users with C++

class Solution {
public:
    void insert_queue(int start, int end, queue<int>& que, vector<vector<int>>& matrix)
    {
        // right
        for (int i = start; i < end; i++)
        {
            que.push(matrix[start][i]);
        }
        // down
        for (int i = start; i < end; i++)
        {
            que.push(matrix[i][end]);
        }
        // left
        for (int i = end; i > start; i--)
        {
            que.push(matrix[end][i]);
        }
        // up
        for (int i = end; i > start; i--)
        {
            que.push(matrix[i][start]);
        }
    }

    void rotate_matrix(int start, int end, queue<int>& que, vector<vector<int>>& matrix)
    {
        // down
        for (int i = start; i < end; i++)
        {
            matrix[i][end] = que.front();
            que.pop();
        }
        // left
        for (int i = end; i > start; i--)
        {
            matrix[end][i] = que.front();
            que.pop();
        }
        // up
        for (int i = end; i > start; i--)
        {
            matrix[i][start] = que.front();
            que.pop();
        }
        // right
        for (int i = start; i < end; i++)
        {
            matrix[start][i] = que.front();
            que.pop();
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        queue<int> que;

        int start = 0, end = matrix.size() - 1;
        while (start < end)
        {
            insert_queue(start, end, que, matrix);
            rotate_matrix(start, end, que, matrix);
            start++;
            end--;
        }
    }
};

[�ٸ� Ǯ�� ���]
1. ��ġ ���(Transpose)�� �����ؼ� ���� �޸� ���� ���� �ϳ��� �������� ������
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        // ��ġ(Transpose) :: ��� ���� �ٲ�
        // 1 2 3    1 4 7    
        // 4 5 6    2 5 8
        // 7 8 9    3 6 9
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // �� ���� ��������, ����� ����
        // 1 4 7    7 4 1    
        // 2 5 8    8 5 2
        // 3 6 9    9 6 3
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
