class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {       
        sort(intervals.begin(), intervals.end()); 
        vector<vector<int>>answer;
        int start = intervals[0][0];
        int end = intervals[0][1];
        if(intervals.size() == 1)
        {
            vector<int> temp = {start,end};
            answer.push_back(temp);
            return answer;
        }
        for(auto e : intervals)
        {
            //현재 start~end의 구간 내부에 포함되는 경우는 그냥 건너뛰기
            if(e[0]>=start && e[1]<=end)continue;
            //다음 요소의 [0]이 end보다 작은 경우 end 갱신
            if(end>=e[0])
                end = e[1];
            //아니라면 서로 다른 구간이므로 answer에 pushback
            else
            {
                vector<int> temp = {start,end};
                answer.push_back(temp);
                start = e[0];
                end = e[1];
            }
        }
        vector<int> temp = {start,end};
        answer.push_back(temp);

        
        
        
        return answer;
    }
};