/*
	Kadane Algorithm
	Runtime: 71 ms ~ 86 ms (94.53% ~ 41.14%)
	Memory: 68 MB ~ 5.73 MB (19.6% ~ 5.73%)
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//https://juneyr.dev/2019-11-21/maximum-subarray 카데인 Kadane 알고리즘

		int bestSum = INT_MIN;
		int endSum = 0;

		for (int num : nums)
		{
			endSum = max(endSum + num, num);
			bestSum = max(endSum, bestSum);
		}

		return bestSum;
	}
};