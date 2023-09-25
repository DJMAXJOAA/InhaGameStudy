class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for(int i=0; i<32; i++) {
            uint32_t tmp = 1 << i;
            uint32_t num = 1 << (31 - i);
            tmp = n & tmp;

            if(tmp)
                ans += num;
        }

        return ans;
    }
};