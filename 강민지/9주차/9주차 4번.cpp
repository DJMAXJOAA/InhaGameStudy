class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        vector<int> input;

        // 이진수로 input에 저장
        while(n > 0)
        {
            input.push_back(n%2);
            n /= 2;
        }

        // 32자리 수에서 채워지지 않는 부분을 0으로 채움
        while(input.size() < 32)
        {
            input.push_back(0);
        }
        
        // 이진수를 십진수로 바꾼 후 answer에 저장
        uint32_t answer = 0;
        int index = 0;

        while(!input.empty())
        {
            answer += pow(2,index++) * input.back();
            input.pop_back();
        }
        
        return answer;
    }
};
