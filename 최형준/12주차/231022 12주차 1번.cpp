[12���� 1��] / Find Minimum in Rotated Sorted Array / 48�� / https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

[���� ����]
��� �˰��� = ���� Ž�� (Binary Search) : O(log n), O(log n)

[������]
1. ��� �Լ��� ������� �ʰ� Ǯ���� �� ���� -> ���� ���⵵�� O(1)�� �߰����� ���� ������ Ǯ�� ����
2. ��Ϳ��� ���� �Ǵܾ��� ������ �� �������� Ž���ϰ� ���� -> low�� high�� ���� ���ؼ� Ž�� �ð��� ���� �� ����

Time taken : 48 m 17 s
Runtime 3ms
Beats 58.73 % of users with C++
Memory 10.51MB
Beats 18.40 % of users with C++

class Solution {
public:
    int size;
    int result;
public:
    void BinarySearch(int low, int mid, int high, vector<int>& nums, int start, int end)
    {
        result = min(result, nums[mid]);

        if (mid == start || mid == end)
        {
            return;
        }

        BinarySearch(low, low + (mid - low) / 2, mid, nums, low, mid);
        BinarySearch(mid, mid + (high - mid + 1) / 2, high, nums, mid, high);
    }

    int findMin(vector<int>& nums) {
        size = nums.size();

        int high = size - 1;
        int low = 0;
        int mid = size / 2;

        result = nums[mid];

        BinarySearch(low, low + (mid - low) / 2, mid, nums, low, mid);
        BinarySearch(mid, mid + (high - mid + 1) / 2, high, nums, mid, high);

        return result;
    }
};

[�ٸ� Ǯ�� ���]
1. while���� ����ϴ� ���� Ž�� ���

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) {
            // �̴� �ּڰ��� ������ ���ݿ� �ִٴ� ���� �ǹ�
            low = mid + 1;
        }
        else {
            // �̴� �ּڰ��� ���� ���ݿ� �ִٴ� ���� �ǹ�
            high = mid;
        }
    }
    return nums[low];
}