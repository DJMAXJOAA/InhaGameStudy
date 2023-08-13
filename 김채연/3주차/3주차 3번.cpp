//Q3.Merge Intervals
//
//1. ������ Ÿ�� : ������ ����
//2. �迭 �� ���Ҹ� ��ġ�� ���� �⺻ ����:
//	i��° ������ end�� i+1��° ������ start���� ũ�� ��ģ��.
//
//3. �⺻������ �����ϱ� ���� �ʿ�����:
//	2���� ���Ͱ� ���ĵǾ� �־���Ѵ�. (ũ�� �񱳸� ����)
//4. ���� ������(intervals)�� ������Ű�� �ͺ��� �⺻���� ���� �� ���ο� �迭�� ��°� �� ����.

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> result; //��ȯ��.
		sort(intervals.begin(), intervals.end());//������ ������ ����.
		result.push_back(intervals[0]); //����� ��ó���� �ϴ� �ְ� ��

		int j = 0;
		for (int i = 1; i < intervals.size(); i++)
		{
			//�⺻ �����κ�
			//result�� �� �ִ� end�� ����
			if (result[j][1] >= intervals[i][0])
			{
				//�ΰ� �� ū �Ÿ� end������ �ִ´�.
				result[j][1] = max(intervals[i][1], result[j][1]);
			}
			else
			{
				//��ġ�� ���� ��� �׳� ����.
				result.push_back(intervals[i]);
				j++;
			}
		}
		return result;
	}
};