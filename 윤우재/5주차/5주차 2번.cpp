class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> answer;
        answer.push_back(0);
        if(n == 0)return answer;
        answer.push_back(1);
        if(n == 1)return answer;
        int cnt = 1;
        int patternLength = 1;
        int left = 1;
        while(1)
        {
            for(int i = left; i<left + patternLength;i++)
            {
                answer.push_back(answer[i]);
                cnt++;
                if(cnt == n) return answer;
            }
            for(int i = left; i<left+patternLength;i++)
            {
                answer.push_back(answer[i]+1);
                cnt++;
                if(cnt == n) return answer;
            }
            left*=2;
            patternLength*=2;
        }
    }
};