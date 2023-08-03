// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint bit = 1;

        for(int i=0; i<32; i++)
        {
            if((n & (bit << i))) ans++;
        }
    
        return ans;
    }
};