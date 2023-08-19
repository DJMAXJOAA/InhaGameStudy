[4���� 1��] / Spiral Matrix / 45�� / https://leetcode.com/problems/spiral-matrix/
�迭���� ��ǥ�� ������ ��� ����

���� ����
1. �迭�� Ž���ϴ� ������ �ٲ�� ������ �װ����� ����
2. �װ����� ���� ��ǥ�� ��� �ٲ���� ��Ģ Ȯ��
3. x, y�� �ۿ� �����ؼ�, �ٲ�� ������ �°� �� �߰�

���� ����
1. �������� �� �պ���
2. ������ ũ�� ���µ�?

// Runtime
// 0ms Beats 100.00 % of users with C++
// Memory 6.94MB
// Beats 23.69 % of users with C++

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        int minX = 0, minY = 1;
        int maxX = matrix[0].size(), maxY = matrix.size();

        bool staright = true;

        int direction = 0;
        int x = 0, y = 0;

        int totalSize = matrix.size() * matrix[0].size();
        while (result.size() < totalSize)
        {
            switch (direction)
            {
            case 0:
            {
                for (; x < maxX; x++)
                {
                    result.push_back(matrix[y][x]);
                    /*cout << matrix[y][x];*/
                }
                x--;
                y++;
                maxX--;
            }
            break;
            case 1:
            {
                for (; y < maxY; y++)
                {
                    result.push_back(matrix[y][x]);
                    /*cout << matrix[y][x];*/
                }
                y--;
                x--;
                maxY--;
            }
            break;
            case 2:
            {
                for (; x >= minX; x--)
                {
                    result.push_back(matrix[y][x]);
                    /*cout << matrix[y][x];*/
                }
                x++;
                y--;
                minX++;
            }
            break;
            case 3:
            {
                for (; y >= minY; y--)
                {
                    result.push_back(matrix[y][x]);
                    /*cout << matrix[y][x];*/
                }
                y++;
                x++;
                minY++;
            }
            break;
            }
            if (direction < 3) direction++;
            else direction = 0;
        }

        return result;
    }
};