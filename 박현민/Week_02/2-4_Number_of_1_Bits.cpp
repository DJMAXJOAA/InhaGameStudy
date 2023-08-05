class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        unsigned int comp = 1;
        for (int i = 32; i > 0; i--, comp *= 2)
        {
            if (n & comp)
                res++;
        }
        return res;
    }
};