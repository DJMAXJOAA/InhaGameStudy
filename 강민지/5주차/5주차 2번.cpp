class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> answer(n+1, 0);
        if(n == 0)  return answer;

        int i = 1, index = 1;
   
        while(1)
        {
            if(i % 2 == 1)  answer[index]++;
            i /= 2;

            if(i == 0)
                i = ++index;

            if(index == n+1)    break;
        }

        return answer;
    }
};
