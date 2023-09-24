//Runtime 0 ms
//Memory 6.5 MB

class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t temp = n;
        uint32_t ans = 0;
        int length = 32;

        while (length > 0)
        {
            int num = temp % 2;
            ans = ans * 2 + num;
            temp /= 2;
            length--;
        }

        return ans;
    }
};

// Runtime 4 ms
// Memory 6.6 MB

//divided and conquer

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);

        return n;

    }
};