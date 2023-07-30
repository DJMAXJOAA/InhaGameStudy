//Q1. Insert Intervals
//��ġ�� �ʴ� Interval���� �־����� ��, ���ο� Interval�� �����ϴ� ����.
//point: ������ �ִ� Interval �� �������� ������ ���� �� �ֱ� ������ �ش� �κп� ���� ó���� �ʿ�
//

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> ans;

	int idx = 0;
	while (idx < intervals.size() && intervals[idx][1] < newInterval[0])
		ans.push_back(intervals[idx++]);

	while (idx < intervals.size() && intervals[idx][0] <= newInterval[1]) {
		newInterval[0] = min(newInterval[0], intervals[idx][0]);
		newInterval[1] = max(newInterval[1], intervals[idx][1]);
		idx++;
	}
	ans.push_back(newInterval);
	while (idx < intervals.size())
		ans.push_back(intervals[idx++]);

	return ans;
}