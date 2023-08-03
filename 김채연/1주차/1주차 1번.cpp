//Q1. Insert Intervals
//��ġ�� �ʴ� Interval���� �־����� ��, ���ο� Interval�� �����ϴ� ����.
//point: ������ �ִ� Interval �� �������� ������ ���� �� �ֱ� ������ �ش� �κп� ���� ó���� �ʿ�

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> ans;

	int idx = 0;
	while (idx < intervals.size() && intervals[idx][1] < newInterval[0])
		ans.push_back(intervals[idx++]); //���ο� Interval �� ��ġ�� Interval �������� �״�� ����

	while (idx < intervals.size() && intervals[idx][0] <= newInterval[1]) {
		newInterval[0] = min(newInterval[0], intervals[idx][0]);
		newInterval[1] = max(newInterval[1], intervals[idx][1]);
		idx++; //��ġ�� Interval �鿡 ���ؼ� �ϳ��� Interval �� �����.
	}
	ans.push_back(newInterval); //��ġ�� Interval �鿡 ���ؼ� �ϳ��� Interval �� ������� ����.
	while (idx < intervals.size()) //���� Interval ���� ����
		ans.push_back(intervals[idx++]);

	return ans;
}