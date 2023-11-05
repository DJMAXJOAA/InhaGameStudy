class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		const int len = nums.size();
		vector<vector<int>> answers;
		int target;

		for (int i = 0; i < len; ++i) {
			//������ ���Ҵ� target(x)���� �缱���� �ȵǵ��� �ǳʶ���
			if (target == -nums[i])
				continue;

			target = -nums[i];
			int left = i + 1, right = len - 1, sum = 0;

			while (left < right) {
				sum = nums[left] + nums[right];
				if (target > sum) {
					++left;
				}
				else if (target < sum) {
					--right;
				}
				else {
					vector<int> temp = { nums[left], -target , nums[right] };
					answers.push_back(temp);

					//������ y,z�� target���� �缱���� �ȵǵ��� �ǳʶ���
					while (left < len && nums[left] == temp[0])
						++left;
					while (right >= 0 && nums[right] == temp[2])
						--right;
				}
			}
		}
		return answers;
	}
};