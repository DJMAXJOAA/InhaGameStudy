//Q3.Merge Intervals
//
//1. 데이터 타입 : 이차원 벡터
//2. 배열 내 원소를 합치기 위한 기본 로직:
//	i번째 원소의 end가 i+1번째 원소의 start보다 크면 겹친다.
//
//3. 기본로직을 보장하기 위한 필요조건:
//	2차원 벡터가 정렬되어 있어야한다. (크기 비교를 위해)
//4. 원본 데이터(intervals)를 변형시키는 것보다 기본로직 수행 후 새로운 배열에 담는게 더 쉽다.

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> result; //반환값.
		sort(intervals.begin(), intervals.end());//이차원 벡터의 정렬.
		result.push_back(intervals[0]); //결과에 맨처음꺼 일단 넣고 비교

		int j = 0;
		for (int i = 1; i < intervals.size(); i++)
		{
			//기본 로직부분
			//result에 들어가 있는 end값 보다
			if (result[j][1] >= intervals[i][0])
			{
				//두값 중 큰 거를 end값으로 넣는다.
				result[j][1] = max(intervals[i][1], result[j][1]);
			}
			else
			{
				//겹치지 않을 경우 그냥 삽입.
				result.push_back(intervals[i]);
				j++;
			}
		}
		return result;
	}
};