class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        vector<int> stack;
        while(n>0)
        {
            stack.push_back(n%2);
            n/=2;
        }
        while (stack.size() < 32)
        {
            stack.push_back(0);
        }
        uint32_t i = 1;
        while(!stack.empty())
        {
            answer += stack.back() * i;
            i *=2;
            stack.pop_back();
        }
        return answer;
    }
    
};