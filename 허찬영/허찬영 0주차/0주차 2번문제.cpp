class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry;
        while(b)
        {
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};
