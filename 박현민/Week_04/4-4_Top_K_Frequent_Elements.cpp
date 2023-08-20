class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> umap;

		int size = nums.size();
		int i;

		for (i = 0; i < size; i++)
		{
			umap[nums[i]]++;
		}

		vector<pair<int, int>> v(umap.begin(), umap.end());

		sort(v.begin(), v.end(), [](pair<int, int> x, pair<int, int> y) {
			if (x.second == y.second)
				return x.first < y.first;
			else
				return x.second > y.second;
			});

		vector<int> ans;
		for (i = 0; i < k; i++)
		{
			ans.push_back(v[i].first);
		}

		return ans;
	}
};
