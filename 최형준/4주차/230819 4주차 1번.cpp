[4주차 1번] / Spiral Matrix / 45분 / https://leetcode.com/problems/spiral-matrix/
배열에서 좌표계 가지고 노는 문제

문제 접근
1. 배열을 탐색하는 방향이 바뀌는 지점을 네가지로 나눔
2. 네가지에 따라 좌표가 어떻게 바뀌는지 규칙 확인
3. x, y를 밖에 선언해서, 바뀌는 지점에 맞게 값 추가

개선 사항
1. 가독성을 좀 손보기
2. 나머진 크게 없는듯?

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