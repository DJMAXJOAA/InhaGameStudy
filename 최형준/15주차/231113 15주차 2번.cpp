[15���� 2��] / Container With Most Water / https://leetcode.com/problems/container-with-most-water/description/

[���� ����]
��� �˰��� = �� ������ O(n), O(1)
1. �迭�� �� ������ ������ ��ҽ�Ű�� �ִ밪 ����

[�ٸ� Ǯ�� ���]
1. ���Ʈ ���� O(n^2), O(1)

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

[�ٸ� Ǯ�� ���]
���Ʈ ���� O(n ^ 2), O(1)
1. ���� ������������ ��ȿ������ ���

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maxArea = 0;

        // ��� ������ �ֿ� ���� �ݺ�
        for (int i = 0; i < height.size(); i++) 
        {
            for (int j = i + 1; j < height.size(); j++) 
            {
                // �� �ֿ� ���� ���� ���
                int area = min(height[i], height[j]) * (j - i);
                // �ִ� ���� ����
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
