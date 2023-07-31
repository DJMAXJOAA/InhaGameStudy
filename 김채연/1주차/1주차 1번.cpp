//Q1. Insert Intervals
//겹치지 않는 Interval들이 주어졌을 때, 새로운 Interval을 삽입하는 문제.
//point: 기존에 있던 Interval 에 겹쳐지는 영역이 있을 수 있기 때문에 해당 부분에 대한 처리가 필요

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> ans;

	int idx = 0;
	while (idx < intervals.size() && intervals[idx][1] < newInterval[0])
		ans.push_back(intervals[idx++]); //새로운 Interval 과 겹치는 Interval 전까지는 그대로 저장

	while (idx < intervals.size() && intervals[idx][0] <= newInterval[1]) {
		newInterval[0] = min(newInterval[0], intervals[idx][0]);
		newInterval[1] = max(newInterval[1], intervals[idx][1]);
		idx++; //겹치는 Interval 들에 대해서 하나의 Interval 로 만든다.
	}
	ans.push_back(newInterval); //겹치는 Interval 들에 대해서 하나의 Interval 로 만든것을 저장.
	while (idx < intervals.size()) //남은 Interval 들을 저장
		ans.push_back(intervals[idx++]);

	return ans;
}