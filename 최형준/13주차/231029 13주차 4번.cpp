[13주차 4번] / Longest Palindromic Substring / 1시간 34분 / https://leetcode.com/problems/longest-palindromic-substring/description/

[문제 접근]
사용 알고리즘 = 중앙 확장 알고리즘 : O(n^2), O(1)
1. 각 문자를 중심으로 양쪽으로 확장하면서 팰린드롬을 확인
2. 확인된 문자는 pair<시작 인덱스, 종료 인덱스>, 팰린드롬 문자 길이
3. 팰린드롬 문자 길이를 저장된 팰린드롬 문자열 길이와 max 비교, 값 최신화

[다른 풀이 방법]
1. 중앙 확장 알고리즘 + 동적 프로그래밍 : O(n ^ 2), O(n ^ 2)
2. Manachers Algorithm : O(n), O(n)
3. 브루트 포스 : O(n^3), O(1)

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

[다른 풀이 방법]
중앙 확장 알고리즘 + 동적 프로그래밍 : O(n ^ 2), O(n ^ 2)
1. 2차원 배열을 사용해서 이미 계산된 부분 문자열이 팰린드롬인지의 여부를 저장
2. dp[i][j] -> dp[i][j] == true라면, s[i] ~ s[j]까지가 팰린드롬을 저장
3. 공간 복잡도를 희생해서 중복 계산을 피함

string longestPalindromeDP(const string& s) {
	int n = s.size();
	vector<vector<bool>> dp(n, vector<bool>(n, false));
	int start = 0, max_length = 1;

	// 모든 단일 문자는 팰린드롬입니다.
	for (int i = 0; i < n; i++)
		dp[i][i] = true;

	// 연속된 두 문자를 확인합니다.
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
			start = i;
			max_length = 2;
		}
	}

	// 길이가 3 이상인 부분 문자열에 대해 팰린드롬 여부를 확인합니다.
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
1. 구분자 (아래는 '#') 을 사용해서 홀수, 짝수 길이의 팰린드롬을 동시에 처리
2. 중앙을 기준으로 최대 반경을 저장 (배열로 저장)
3. 팰린드롬 문자열 특화 알고리즘으로, 좀 고급 알고리즘이라 솔직히 몰라도 될듯 (https://m.blog.naver.com/jqkt15/222108415284)

string longestPalindromeManacher(const string& s) {
	// 가공된 새로운 문자열을 생성합니다. 
	// 중간 중간에 #을 넣어서 홀수 길이만 고려하게 됩니다.
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

		// 중앙을 기준으로 확장합니다.
		while (T[i + (1 + P[i])] == T[i - (1 + P[i])])
			P[i]++;

		// R과 C를 업데이트합니다.
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}

	// 가장 긴 팰린드롬을 찾습니다.
	int max_length = 0, center_index = 0;
	for (int i = 1; i < n - 1; i++) {
		if (P[i] > max_length) {
			max_length = P[i];
			center_index = i;
		}
	}

	return s.substr((center_index - 1 - max_length) / 2, max_length);
}

브루트 포스 : O(n ^ 3), O(1)
1. 문자열의 모든 가능한 부분 문자열 생성
2. 각각 팰린드롬인지 모두 체크
3. 굉장히 비효율적이지만 제일 생각하기 쉽고, 이런 방법이 있다는것만 체크

string longestPalindromeBruteForce(const string& s) {
	int n = s.size(), max_length = 0, start = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int left = i, right = j;
			bool is_palindrome = true;

			// 팰린드롬인지 확인합니다.
			while (left < right) {
				if (s[left++] != s[right--]) {
					is_palindrome = false;
					break;
				}
			}

			// 팰린드롬이면 최대 길이를 업데이트합니다.
			if (is_palindrome && j - i + 1 > max_length) {
				max_length = j - i + 1;
				start = i;
			}
		}
	}

	return s.substr(start, max_length);
}
