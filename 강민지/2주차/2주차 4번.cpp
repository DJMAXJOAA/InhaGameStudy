class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int answer = 0;
        while(n > 0)
        {
            if(n % 2 == 1)  
                answer++;
            
            n /= 2;
        }
        
        return answer;
    }
};

// bit로 풀면 runtime ↑ memory ↓
// 내꺼로 풀면 runtime ↓ memory ↑
