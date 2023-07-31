//Q4. �־��� ���ڿ����� ���ĺ��� �ߺ����� �ʰ� 
//    ���� ��� ���ӵǴ� ���ڿ� �Ϻθ� ��ȯ�϶�

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<char> Words;
		int nMax = 0;

		for (int i = 0; i < s.size(); i++)
		{
			//������ ���� �� �ߺ��� ���� �ִ��� Ȯ��
			vector<char>::iterator iter = find(Words.begin(), Words.end(), s[i]);

			if (iter != Words.end())		// ������ nMax ���� �� ���ڿ� ����
			{
				if (nMax < Words.size())	nMax = Words.size();
				Words.erase(Words.begin(), ++iter);	// ??���Ŵ� �ߺ��� ���ڱ���??
				Words.push_back(s[i]);
			}
			else
			{
				Words.push_back(s[i]);		// �ߺ����� �ʾ����� ���� �߰�
			}
		}
		if (nMax < Words.size())	nMax = Words.size();	// ���ڿ��� ��� Ž���� �� nMax ����

		return nMax;
	}

};