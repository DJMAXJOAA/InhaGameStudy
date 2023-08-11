// Q4. Number of 1 Bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        //     int cnt = 0;
        // while(n != 0) {
        //     cnt = cnt + (n & 1); -> ??
        //     n = n>>1;
        // }
        // return cnt;

        // int cnt = 0;
        // for(int i = 0; i < 32; i++) {
        //     if(n & (1 << i)) cnt++;
        // }
        // return cnt;       

        //Àç±Í
        // return n == 0 ? 0 : 1 + hammingWeight(n & (n - 1));

    }
};