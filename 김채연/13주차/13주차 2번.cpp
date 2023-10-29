//�߰��� ã�� mid = (l + h) / 2
//Ű�� �߰� ������ ������ mid�� ��ȯ�մϴ�.
//Else arr[l..mid]�� ���ĵ� ���
//a) �˻��� Ű�� arr[l]����
//arr[mid] ������ ������ arr[l..mid]�� ���� �ݺ��˴ϴ�.
//b) �׷��� ������ arr[mid + 1..h]�� ���� �ݺ��˴ϴ�.
//Else(arr[mid + 1..h]�� ���ĵǾ�� ��)
//a) �˻��� Ű�� arr[mid + 1]����
//arr[h] ������ ������ arr[mid + 1..h]�� ���� �ݺ��˴ϴ�.
//b) arr[l..mid]�� ���� �ݺ�

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1, mid;
        while (beg <= end)
        {
            mid = (beg + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[beg] <= nums[mid])
            {
                if (target <= nums[mid] && target >= nums[beg])
                    end = mid - 1;
                else
                    beg = mid + 1;
            }

            else
            {
                if (target >= nums[mid] && target <= nums[end])
                    beg = mid + 1;
                else
                    end = mid - 1;
            }

        }
        return -1;
    }
    
};

