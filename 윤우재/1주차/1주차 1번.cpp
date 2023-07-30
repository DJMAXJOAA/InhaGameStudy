class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if(intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int start = newInterval.front();
        int end = newInterval.back();
        bool isStartInInterval = false;
        bool isEndInInterval = false;
        intervals.insert(intervals.begin(), vector<int>{-999,-999});
        intervals.push_back(vector<int>{INT_MAX,INT_MAX});

        int startIdx, endIdx;
        for(int i = 0; i<intervals.size();i++)
        {
            // 구간 내에 있는지 판단
            if(start>=intervals[i].front() &&start<=intervals[i].back())
            {
                startIdx = i;
                isStartInInterval = true;
                break;
            }
            if(start>intervals[i].back() && start<intervals[i+1].front())
            {
                startIdx = i;
                break;
            }
        }
        for(int i = 0; i<intervals.size();i++)
        {
            // 구간 내에 있는지 판단
            if(end>=intervals[i].front() &&end<=intervals[i].back())
            {
                endIdx = i;
                isEndInInterval = true;
                break;
            }
            if(end>intervals[i].back() && end<intervals[i+1].front())
            {
                endIdx = i;
                break;
            }
        }
        //cout<<startIdx<<" "<<endIdx<<endl;

        vector<int> temp;
        if(isStartInInterval)
            temp.push_back(intervals[startIdx].front());
        else
            temp.push_back(newInterval.front());

        if(isEndInInterval)
            temp.push_back(intervals[endIdx].back());
        else
            temp.push_back(newInterval.back());

        if((!isStartInInterval && !isEndInInterval) && (startIdx == endIdx))
        {
            intervals.insert(intervals.begin()+startIdx+1,temp);
        }
        else
        {
            if(isStartInInterval)
            {
                for(int i = 0; i< (endIdx - startIdx+1);i++)
                {
                    intervals.erase(intervals.begin()+startIdx);
                }
                intervals.insert(intervals.begin()+startIdx, temp);
            }
            else
            {
                for(int i = 0; i<(endIdx - startIdx);i++)
                {
                    intervals.erase(intervals.begin()+startIdx+1);
                }
                intervals.insert(intervals.begin()+startIdx+1, temp);
            }
            
               
            //intervals.insert(intervals.begin()+startIdx, temp);
        }
        if(intervals.front() == vector<int>{-999,-999})
            intervals.erase(intervals.begin());
        if(intervals.back() == vector<int>{INT_MAX,INT_MAX})
            intervals.pop_back();
        return intervals;
    }
    
};