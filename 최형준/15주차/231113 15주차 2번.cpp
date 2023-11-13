[15주차 2번] / Container With Most Water / https://leetcode.com/problems/container-with-most-water/description/

[문제 접근]
사용 알고리즘 = 투 포인터 O(n), O(1)
1. 배열의 양 끝에서 범위를 축소시키며 최대값 갱신

[다른 풀이 방법]
1. 브루트 포스 O(n^2), O(1)

Time taken : 10 m 27 s
Runtime 77ms
Beats 22.02 % of users with C++
Memory 59.25MB
Beats 87.65 % of users with C++

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;

        while (left < right)
        {
            int current = min(height[left], height[right]) * (right - left);
            result = max(result, current);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return result;
    }
};

[다른 풀이 방법]
브루트 포스 O(n ^ 2), O(1)
1. 가장 직관적이지만 비효율적인 방법

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maxArea = 0;

        // 모든 가능한 쌍에 대해 반복
        for (int i = 0; i < height.size(); i++) 
        {
            for (int j = i + 1; j < height.size(); j++) 
            {
                // 각 쌍에 대한 면적 계산
                int area = min(height[i], height[j]) * (j - i);
                // 최대 면적 갱신
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
