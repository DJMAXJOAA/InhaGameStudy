class Solution {
public:

int findMin(vector<int>& nums) {
    if(nums.size() == 1)
        return nums[0];

	int left = 0;
	int right = nums.size() - 1;
	while (left < right)
	{
		int cur = (right + left) / 2;
		cout << cur << endl;
		if (nums[cur] > nums[(cur + 1) % nums.size()])
			return nums[(cur + 1) % nums.size()];
		else
		{
			if (nums[left] > nums[cur])
			{
				right = cur;
				continue;
			}
			if (nums[right] < nums[cur])
			{
				left = cur;
				continue;
			}
			//둘 다 안속한다면 회전 안한거지
			return nums[0];
		}
	}
    return 0;
}
};