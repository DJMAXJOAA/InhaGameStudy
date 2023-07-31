//Q4. 주어진 문자열에서 알파벳이 중복되지 않고 
//    가장 길게 연속되는 문자열 일부를 반환하라

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<char> Words;
		int nMax = 0;

		for (int i = 0; i < s.size(); i++)
		{
			//진행한 문자 중 중복된 값이 있는지 확인
			vector<char>::iterator iter = find(Words.begin(), Words.end(), s[i]);

			if (iter != Words.end())		// 있으면 nMax 갱신 및 문자열 제거
			{
				if (nMax < Words.size())	nMax = Words.size();
				Words.erase(Words.begin(), ++iter);	// ??제거는 중복된 문자까지??
				Words.push_back(s[i]);
			}
			else
			{
				Words.push_back(s[i]);		// 중복되지 않았으면 문자 추가
			}
		}
		if (nMax < Words.size())	nMax = Words.size();	// 문자열을 모두 탐색한 후 nMax 갱신

		return nMax;
	}

};