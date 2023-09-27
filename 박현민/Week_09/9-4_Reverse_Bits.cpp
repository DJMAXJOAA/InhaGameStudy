/*
    Divide
    Runtime: 2 ms ~ 5 ms (47.61% ~ 7.66%)
    Memory: 6.3 MB ~ 6.6 MB (18.30% ~ 5.80%)
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 31; i > -1; i--)
        {
            if (n % 2)
            {
                res += pow(2, i);
            }
            n /= 2;
        }

        return res;
    }
};

/*
    Shift with Bit Operation
    Runtime: 2 ms ~ 4 ms (47.61% ~ 36.84%)
    Memory: 6.2 MB ~ 6.4 MB (24.86% ~ 5.80%)
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 32; i > 0; i--)
        {
            res *= 2;
            res += n & 1;

            n = n >> 1;
        }

        return res;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            res += n & 1;
            n >>= 1;
        }

        return res;
    }
};
