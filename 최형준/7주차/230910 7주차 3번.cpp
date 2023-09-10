[7���� 3��] / Product of Array Except Self / 18�� / https://leetcode.com/problems/product-of-array-except-self/

[���� ����]
��� �˰��� = �ؽø�
1.  �ʿ� ��� ����� ���ԵǾ��ִ���, �ȵǾ��ִ��� üũ
2.  �ȵǾ� ������ multiplication �Լ���, �ش� �ε����� ���� ������ ���� ��� �� map�� ����
3.  �̹� �ߺ� ���� ����Ǿ������� map�� �˻� ��� ��ȯ
4.  ���� �迭�� ���� �� ��ȯ

[������]
1.  nums[i]�� ������ -30~30������ �̸� ����� �����صδ� map�� ����ߴµ�, �־��� ��� O(n^2)���� �� �� ����
2.  ������ Ǯ����� ������ ������ �䱸�ϴ� ������ O(n)���� �ش���� ����

[�ٸ� Ǯ�� ���]
1. Left, Right�� ������ �ΰ� ���(O(n))

// Time taken : 18 m 16 s
// Runtime 11ms
// Beats 98.02 % of users with C++
// Memory 24.02MB
// Beats 62.18 % of users with C++

class Solution {
public:
    int multiplication(const vector<int>& nums, int index)
    {
        int result = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == index)
                continue;
            result *= nums[i];
        }
        return result;
    }

    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> result(nums.size());
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = mp.find(nums[i]);
            if (iter == mp.end())
            {
                int mutiple = multiplication(nums, i);
                mp[nums[i]] = mutiple;
                result[i] = mutiple;
            }
            else
            {
                result[i] = iter->second;
            }
        }

        return result;
    }
};


[�ٸ� Ǯ�� ���]
1. Left, Right�� ������ �ΰ� ���(O(n))

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);

        // left product = ���� ���(�ڽ��� ��ġ���� ��ĭ �������� ���� ������)
        // �ڽ� ��ġ �迭�� ����ص�
        int left_product = 1;
        for (int i = 1; i < n; i++)
        {
            left_product *= nums[i - 1];
            answer[i] = left_product;
        }

        // �ڽ��� ��ġ ���� ������ ������ �������� ���� �ڽ��� ���� ����
        int right_product = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            right_product *= nums[i + 1];
            answer[i] *= right_product;
        }

        return answer;
    }
};