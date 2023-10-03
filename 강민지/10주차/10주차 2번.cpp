class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)    return 0;

        priority_queue<int> temp;
        int answer = 1;
        int maxAnswer = 1;
        int first = 0;

        // nums를 오름차순으로 정렬
        for(int i = 0; i < nums.size(); i++)
        {
            temp.push(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            // temp의 첫번째 원소로 비교
            first = temp.top();
            temp.pop();

            // 연속적일 때
            if(first == temp.top() + 1)
            {
                answer++;
                if(maxAnswer < answer) maxAnswer = answer; // 최대값일때 정답 갱신 
            }
            // 같은 수가 반복될 때
            else if(first == temp.top())
            {
                continue;
            }
            // 연속X -> answer 초기화
            else
            {
                answer = 1;
            }
        }
        
        return maxAnswer;
    }
};
