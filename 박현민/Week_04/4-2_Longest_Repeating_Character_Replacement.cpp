class Solution {
public:
	int characterReplacement(string s, int k) {

		int size = s.size();
		int ans = 0, maxCount = 0, start = 0;
		int counts[26] = { 0, };

		for (int i = 0; i < size; i++)
		{
			counts[s[i] - 'A']++;
			maxCount = max(counts[s[i] - 'A'], maxCount);

			if ((i - start + 1) - (maxCount) > k)
			{
				counts[s[start] - 'A']--;
				start++;
			}

			ans = max(ans, i - start + 1);
		}

		return ans;
	}
};
