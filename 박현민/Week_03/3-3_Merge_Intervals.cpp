class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b)
	{
		return a[0] < b[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		if (intervals.empty())
		{
			return res;
		}

		sort(intervals.begin(), intervals.end(), cmp);
		for (int i = 0; i < intervals.size(); i++)
		{
			bool isPush = true;
			for (int j = 0; j < res.size(); j++)
			{
				if (res[j][1] >= intervals[i][0])
				{
					res[j][1] = max(res[j][1], intervals[i][1]);
					isPush = false;
				}
			}
			if (isPush)
			{
				res.push_back(intervals[i]);
			}
		}
		return res;
	}
};