class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();

        if (n == 1)
        {
            if (nums[0] == target) return 0;
            else return -1;
        }

        int size = n / 2;
        int start = 0;
        int mid = n / 2;
        int end = n - 1;
        int ans = -1;

        while (size > 0)
        {
            if (target < nums[mid])
            {
                if (nums[start] > target)
                {
                    if (nums[start] > nums[mid])
                    {
                        end = mid - 1;
                        mid = (start + end) / 2;
                    }

                    else
                    {
                        start = mid + 1;
                        mid = (start + end) / 2;
                    }

                }

                else if (nums[start] < target)
                {
                    end = mid - 1;
                    mid = (start + end) / 2;
                }

                else
                {
                    return start;
                }
            }

            else if (target > nums[mid])
            {
                if (nums[end] > target)
                {
                    start = mid + 1;
                    mid = (start + end) / 2;
                }

                else if (nums[end] < target)
                {
                    if (nums[mid] > nums[end])
                    {
                        start = mid + 1;
                        mid = (start + end) / 2;
                    }

                    else
                    {
                        end = mid - 1;
                        mid = (start + end) / 2;
                    }

                }

                else
                {
                    return end;
                }
            }

            else
            {
                return mid;
            }

            size /= 2;
        }

        if (nums[mid] == target) return mid;

        return ans;
    }
};