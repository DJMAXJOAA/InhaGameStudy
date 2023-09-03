[6주차 3번] / Rotate Image / 37분 / https://leetcode.com/problems/rotate-image/

[문제 접근]
사용 알고리즘 = 큐를 이용해서 주소값을 임시 저장
1. start = 0, end = 배열의 마지막부분값으로 설정
2. insert_queue() 외곽선 값의 주소값 대입
3. rotate_matrix() 저장했던 큐의 값을 pop 시키면서 인덱스 설정
4. start++, end-- 해서 크기가 start < end면 한번 더(내부의 매트릭스도 설정)

[개선점]
1. 큐를 따로 설정하지 않고 바로 스왑시켜도 됨
2. 함수를 두개로 나누지 않고, 하나의 과정에서 끝낼 수 있음

[다른 풀이 방법]
1. 전치 행렬(Transpose)를 수행해서 따로 메모리 저장 없이 하나의 과정으로 뒤집기

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

[다른 풀이 방법]
1. 전치 행렬(Transpose)를 수행해서 따로 메모리 저장 없이 하나의 과정으로 뒤집기
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        // 전치(Transpose) :: 행과 열을 바꿈
        // 1 2 3    1 4 7    
        // 4 5 6    2 5 8
        // 7 8 9    3 6 9
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 각 행을 뒤집으면, 결과가 나옴
        // 1 4 7    7 4 1    
        // 2 5 8    8 5 2
        // 3 6 9    9 6 3
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
