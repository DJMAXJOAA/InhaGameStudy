class Solution {
public:
    int getSum(int a, int b) {
        int sign = 1;
        if (a < 0 && b < 0)
        {
            a = abs(a);
            b = abs(b);
            sign = -1;
        }

        int carry = 0;
        while (true)
        {
            if ((a & b) < 0)
                carry = 0;
            else
                carry = (a & b) << 1;
            a = a ^ b;
            if (carry == 0)
                return a * sign;
            else
                b = carry;
        }
    }
};
