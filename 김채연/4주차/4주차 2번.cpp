// Q2. Longest Repeating Character Replacement
// k = ��ü������ ���ڿ��� ��
// 
// �־��� ���ڿ����� k��ŭ�� ���ڸ� �ٸ� ���ڷ� ��ü�� �����ϴٰ� ���� ��, 
// ������ ���ڷ� ���� ��� ���� �� �ִ� ������ ���̴� ���ΰ�?

// ���ڿ��� �ִ���̴� 50,000�̹Ƿ� �ܼ��� ���� �õ��غ��� ���� ����
// �����̵� ������ ����� �̿��ϸ� �� ���� search�� O(N)���� ���� ���� �� �ִ�.

class Solution {
public:
	int characterReplacement(string s, int k) {
		int maxLen = 0;	//������ �ִ� ����
		vector<int> letterCount(26, 0);

		int left = 0, right = 0, windowSize = 0;
		int maxFrequency = 0;

		for (; right < s.length(); ++right) {

			++letterCount[s[right] - 'A']; //�����츦 ���������� ��ĭ �ø�
			maxFrequency = max(maxFrequency, letterCount[s[right] - 'A']);	//�߰��� ���ڷ� ���� maxFreq ������Ʈ

			windowSize = right - left + 1;
			if (windowSize - maxFrequency > k) {	//�ش� �����쿡���� ���̻� k�� ��ȯ���� ��� ���ڰ� ������ �� ������

				maxLen = max(maxLen, windowSize - 1);	//���� ũ��� ��

				//�������� ������ ��ĭ ����
				--letterCount[s[left] - 'A'];
				maxFrequency = max(maxFrequency, letterCount[s[left] - 'A']);	//�����쿡���� �ִ� �� �� ������Ʈ
				++left;
			}

		}

		return max(maxLen, right - left);	//K������ ���ڰ� ����� ��� ���
	}
};