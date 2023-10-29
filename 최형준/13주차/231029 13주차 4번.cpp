[13���� 4��] / Longest Palindromic Substring / 1�ð� 34�� / https://leetcode.com/problems/longest-palindromic-substring/description/

[���� ����]
��� �˰��� = �߾� Ȯ�� �˰��� : O(n^2), O(1)
1. �� ���ڸ� �߽����� �������� Ȯ���ϸ鼭 �Ӹ������ Ȯ��
2. Ȯ�ε� ���ڴ� pair<���� �ε���, ���� �ε���>, �Ӹ���� ���� ����
3. �Ӹ���� ���� ���̸� ����� �Ӹ���� ���ڿ� ���̿� max ��, �� �ֽ�ȭ

[�ٸ� Ǯ�� ���]
1. �߾� Ȯ�� �˰��� + ���� ���α׷��� : O(n ^ 2), O(n ^ 2)
2. Manachers Algorithm : O(n), O(n)
3. ���Ʈ ���� : O(n^3), O(1)

Time taken : 1 hr 34 m 8 s
Runtime 27ms
Beats 62.01 % of users with C++
Memory 7.21MB
Beats 82.13 % of users with C++

class Solution {
public:
	int size;
	bool Palindrome(int start, int end, string& s)
	{
		if (start < 0 || end >= size)
			return false;

		return s[start] == s[end];
	}

	string longestPalindrome(string s) {
		size = s.size();

		pair<int, int> savePoint = make_pair(0, 0);
		int saveLength = 1;

		int interval, length;
		pair<int, int> point;
		for (int i = 1; i < size; i++)
		{
			interval = 1;
			length = 1;

			while (Palindrome(i - interval, i + interval, s))
			{
				point = make_pair(i - interval, i + interval);
				interval++;
				length += 2;
			}
			if (length > saveLength)
			{
				saveLength = length;
				savePoint = point;
			}
		}

		for (int i = 1; i < size; i++)
		{
			interval = 0;
			length = 0;

			while (Palindrome(i - 1 - interval, i + interval, s))
			{
				point = make_pair(i - 1 - interval, i + interval);
				interval++;
				length += 2;
			}
			if (length > saveLength)
			{
				saveLength = length;
				savePoint = point;
			}
		}

		return s.substr(savePoint.first, savePoint.second - savePoint.first + 1);
	}
};

[�ٸ� Ǯ�� ���]
�߾� Ȯ�� �˰��� + ���� ���α׷��� : O(n ^ 2), O(n ^ 2)
1. 2���� �迭�� ����ؼ� �̹� ���� �κ� ���ڿ��� �Ӹ���������� ���θ� ����
2. dp[i][j] -> dp[i][j] == true���, s[i] ~ s[j]������ �Ӹ������ ����
3. ���� ���⵵�� ����ؼ� �ߺ� ����� ����

string longestPalindromeDP(const string& s) {
	int n = s.size();
	vector<vector<bool>> dp(n, vector<bool>(n, false));
	int start = 0, max_length = 1;

	// ��� ���� ���ڴ� �Ӹ�����Դϴ�.
	for (int i = 0; i < n; i++)
		dp[i][i] = true;

	// ���ӵ� �� ���ڸ� Ȯ���մϴ�.
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
			start = i;
			max_length = 2;
		}
	}

	// ���̰� 3 �̻��� �κ� ���ڿ��� ���� �Ӹ���� ���θ� Ȯ���մϴ�.
	for (int length = 3; length <= n; length++) {
		for (int i = 0; i < n - length + 1; i++) {
			int j = i + length - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1]) {
				dp[i][j] = true;
				start = i;
				max_length = length;
			}
		}
	}

	return s.substr(start, max_length);
}




Manachers Algorithm : O(n), O(n)
1. ������ (�Ʒ��� '#') �� ����ؼ� Ȧ��, ¦�� ������ �Ӹ������ ���ÿ� ó��
2. �߾��� �������� �ִ� �ݰ��� ���� (�迭�� ����)
3. �Ӹ���� ���ڿ� Ưȭ �˰�������, �� ��� �˰����̶� ������ ���� �ɵ� (https://m.blog.naver.com/jqkt15/222108415284)

string longestPalindromeManacher(const string& s) {
	// ������ ���ο� ���ڿ��� �����մϴ�. 
	// �߰� �߰��� #�� �־ Ȧ�� ���̸� ����ϰ� �˴ϴ�.
	string T = "#";
	for (char c : s) {
		T += c;
		T += "#";
	}
	int n = T.size(), C = 0, R = 0;
	vector<int> P(n, 0);

	for (int i = 1; i < n - 1; i++) {
		int mirr = 2 * C - i;
		if (i < R)
			P[i] = min(R - i, P[mirr]);

		// �߾��� �������� Ȯ���մϴ�.
		while (T[i + (1 + P[i])] == T[i - (1 + P[i])])
			P[i]++;

		// R�� C�� ������Ʈ�մϴ�.
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}

	// ���� �� �Ӹ������ ã���ϴ�.
	int max_length = 0, center_index = 0;
	for (int i = 1; i < n - 1; i++) {
		if (P[i] > max_length) {
			max_length = P[i];
			center_index = i;
		}
	}

	return s.substr((center_index - 1 - max_length) / 2, max_length);
}

���Ʈ ���� : O(n ^ 3), O(1)
1. ���ڿ��� ��� ������ �κ� ���ڿ� ����
2. ���� �Ӹ�������� ��� üũ
3. ������ ��ȿ���������� ���� �����ϱ� ����, �̷� ����� �ִٴ°͸� üũ

string longestPalindromeBruteForce(const string& s) {
	int n = s.size(), max_length = 0, start = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int left = i, right = j;
			bool is_palindrome = true;

			// �Ӹ�������� Ȯ���մϴ�.
			while (left < right) {
				if (s[left++] != s[right--]) {
					is_palindrome = false;
					break;
				}
			}

			// �Ӹ�����̸� �ִ� ���̸� ������Ʈ�մϴ�.
			if (is_palindrome && j - i + 1 > max_length) {
				max_length = j - i + 1;
				start = i;
			}
		}
	}

	return s.substr(start, max_length);
}
