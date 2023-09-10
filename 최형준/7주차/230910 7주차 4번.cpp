[7���� 4��] / Missing Number / 7�� / https://leetcode.com/problems/missing-number/

[���� ����]
��� �˰��� = �׳� �迭�� �� ����
1.  nums �迭�� ������ ���鼭 numbers �迭�� ����
2.  numbers �迭�� ������ ���鼭 0�� �� ã��
3.  ������ size ��ȯ

[������]
1.  nums�� ���� �������� ������ �����ϴ� �������⵵�� ��������
    �߰� ������ �Ⱦ��� Ǫ�� ����� ã�ƺ���

[�ٸ� Ǯ�� ���]
1.  ���콺 ���� �̿��� Ǯ��

// Time taken : 7 m 13 s
// Runtime 11ms
// Beats 90.37 % of users with C++
// Memory 18.44MB
// Beats 7.77 % of users with C++

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> numbers(size + 1, 0);

        for (int i = 0; i < size; i++)
        {
            numbers[nums[i]]++;
        }

        for (int i = 0; i < size; i++)
        {
            if (numbers[i] == 0)
                return i;
        }
        return size;
    }
};

// [�ٸ� Ǯ�� ���]
// 1.  ���콺 ���� �̿��� Ǯ��

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();

        // ���콺 ���� �̿��ؼ�, �̸� total�� nums�� ���� �ִ´�
        int total = (n * (n + 1)) / 2;

        for (int num : nums)
        {
            // �迭�� ���鼭 �ش� nums �ε����� ���� ��� ����
            total -= num;
        }

        // ��� ���� ���� ���� ���� �����̴�
        return total;
    }
};