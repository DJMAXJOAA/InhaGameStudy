// Q2. Longest Repeating Character Replacement
// k = 교체가능한 문자열의 수
// 
// 주어진 문자열에서 k만큼의 문자를 다른 문자로 교체가 가능하다고 했을 때, 
// 동일한 문자로 가장 길게 만들 수 있는 문자의 길이는 얼마인가?

// 문자열의 최대길이는 50,000이므로 단순히 전부 시도해보는 것은 무리
// 슬라이딩 윈도우 기법을 이용하면 한 번의 search로 O(N)만에 답을 구할 수 있다.

class Solution {
public:
	int characterReplacement(string s, int k) {
		int maxLen = 0;	//정답의 최대 길이
		vector<int> letterCount(26, 0);

		int left = 0, right = 0, windowSize = 0;
		int maxFrequency = 0;

		for (; right < s.length(); ++right) {

			++letterCount[s[right] - 'A']; //윈도우를 오른쪽으로 한칸 늘림
			maxFrequency = max(maxFrequency, letterCount[s[right] - 'A']);	//추가된 문자로 인한 maxFreq 업데이트

			windowSize = right - left + 1;
			if (windowSize - maxFrequency > k) {	//해당 윈도우에서는 더이상 k개 변환으로 모든 문자가 같아질 수 없을때

				maxLen = max(maxLen, windowSize - 1);	//이전 크기로 비교

				//윈도우의 왼쪽을 한칸 줄임
				--letterCount[s[left] - 'A'];
				maxFrequency = max(maxFrequency, letterCount[s[left] - 'A']);	//윈도우에서의 최대 빈도 수 업데이트
				++left;
			}

		}

		return max(maxLen, right - left);	//K이하의 문자가 변경는 경우 대비
	}
};